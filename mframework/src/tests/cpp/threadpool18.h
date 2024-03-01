#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>

#include <future>///
#include <functional>
#include <stdexcept>///

#include <condition_variable>



class ThreadPool
{
    private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex         queue_mutex;
    std::condition_variable condition;
    bool stop;
    public:
    ThreadPool(int threads)
    :stop(false)
    {
        for(int i = 0; i < threads;i++)
        {
            workers.emplace_back(std::thread(
                [this]{
                        for(;;)
                        {
                            std::function<void()> task;
                            {
                                std::unique_lock<std::mutex> lock(queue_mutex);

                                //lock.wait([this]{ return this->stop || !this->tasks.empty();});
                                condition.wait(lock,[this]{ return this->stop || !this->tasks.empty();});

                                if(this->stop && this->tasks.empty()) return;

                                task = std::move(this->tasks.front());
                                this->tasks.pop();
                            }
                            task();
                        }

                }
            ));
        }
    };


    //auto enqueue(F &&f,Args... args)->tepyname std::result_of<F(Args...)>
    template<class F,class... Args>
    auto enqueue(F &&f,Args&&... args)->std::future< typename std::result_of<F(Args...)>::type>
    {
        //using return_type = typename std::result_of(F(Args...));
        using return_type = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f),std::forward<Args>(args)...)
        );

        //std::feature<std::function<void()>> res = task.get_feature();
        std::future<return_type> res = task->get_future();

        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            if(stop)
             throw std::runtime_error("enqueue on stopped pool!");

            //tasks.push_back((){ task();});
            tasks.emplace([task]{ (*task)();});//store a lambda
        }

        condition.notify_one();

        return res;
    };
    ThreadPool(const ThreadPool&) = delete;


    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();

        for(std::thread &worker:workers)
        {
            worker.join();
        }
    };

};