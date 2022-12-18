#include <iostream>
#include <future>
#include <thread>
#include <condition_variable>
#include <mutex>

int func()
{
    std::condition_variable cv;
    std::mutex m;
    bool flag = false;
    std::thread th([&]()
                   {
        {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock,[&](){return flag;});
            std::cout <<"wait signal!"<<std::endl;
        } });


    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::unique_lock<std::mutex> lock(m);
        flag = true;
        std::cout <<"flag = true."<<std::endl;
        cv.notify_one();
    }


    th.join();

    return 0;
}



class ThreadRAII{
    public:
    ThreadRAII(std::thread &&thread)
    :t(std::move(thread))
    {
    };
    ~ThreadRAII(){
        if(t.joinable()) {
            t.join();
        }
    }
    private:
    std::thread t;
};

int func3()
{
    std::promise<void> prom;
    ThreadRAII t(std::thread([&](){
        prom.get_future().wait();
        std::cout << "th executing!"<<std::endl;
    }));


    std::cout << "prom.set_value"<<std::endl;
    prom.set_value();

    return 0;
};

int main()
{
    func3();
    return 0;
}