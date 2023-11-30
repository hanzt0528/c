#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <future>
#include <functional>
#include <condition_variable>
#include <stdexcept>


class ThreadPool
{
    private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
    using lock_type = typename std::unique_lock<std::mutex>;
    public:
    ThreadPool(size_t threads)
    :stop(false)
    {
        for(size_t i = 0; i < threads; i++)
        {
            workers.emplace_back(std::thread(
                [this]
                {
                    for(;;)
                    {
                        std::function<void()> task;
                        {
                            lock_type lock(queue_mutex);
                            condition.wait(lock,[this]{return this->stop || ! tasks.empty();});

                            if(this->stop && tasks.empty())
                                return;

                            task = std::move(this->tasks.front());
                            this->tasks.pop();
                        }
                        task();
                        
                    }
                }
            ));
        }
    }

    template<class F,class... Args>
    auto enqueue(F &&f,Args... args) -> std::future< typename std::result_of<F(Args...)>::type>
    {
        using return_type = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f),std::forward<Args>(args)...)
        );

        std::future<return_type> res = task->get_future();

        {
            lock_type lock(queue_mutex);
            if(stop == true)
                throw std::runtime_error("enqueue on stopped threadpool!");

            tasks.emplace([task]{(*task)();});

            condition.notify_one();
        }
        return res;
    }

    ~ThreadPool()
    {
        {
            lock_type lock(queue_mutex);
            stop = true;
            condition.notify_all();
        }
        for(std::thread &worker :workers)
        {
            worker.join();
        }
    }
};
