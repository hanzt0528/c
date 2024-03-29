#include <vector>
#include <queue>
#include <thread>
#include <future>
#include <mutex>
#include <functional>
#include <stdexcept>
#include <condition_variable>


class ThreadPool
{
    private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;

    public:
    ThreadPool(size_t threads)
    {
        for(size_t i = 0; i < threads; i++)
        {
            workers.emplace_back(
                std::thread([this]{

                    for(;;)
                    {
                        std::function<void()> task;
                        {
                            std::unique_lock<std::mutex> lock(queue_mutex);
                            condition.wait(lock,[this]{return this->stop || ! this->tasks.empty();});
                            if(this->stop && this->tasks.empty())
                                return;

                            task = std::move(tasks.front());
                            tasks.pop();
                        }
                        task();
                    }
                })
            );
        }
    }


     //typename
     //return_type()
     //return res;
    template<class F,class... Args>
    auto enqueue(F &&f,Args... args) ->std::future<typename std::result_of<F(Args...)>::type>
    {
        using return_type = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f),std::forward<Args>(args)...)
        );

        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            if(this->stop)
                throw std::runtime_error("enqueue on stopped threadpool");

            tasks.emplace([task]{(*task)();});
        }

        condition.notify_one();

        return res;
    }

    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
            condition.notify_all();
        }
        for(std::thread &worker:workers)
        {
            worker.join();
        }
    }
};