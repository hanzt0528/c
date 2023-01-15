#include <iostream>
#include <iomanip> //std::put_time
#include <thread> //std::this_thread::sleep_until
#include <chrono> //std::chrono::system_clock
#include <ctime>  //std::time_t;std::tm;std::localtime;std::mktime
#include <mutex>
#include <future>
using namespace std::chrono_literals;

bool exits = false;
std::timed_mutex tm;

std::promise<void> prom;
std::future<void> f = prom.get_future();
int work()
{
    while(!exits)
    {
        if(tm.try_lock_for(2s))
        {
             //std::this_thread::sleep_for(2s);
            std::cout <<"success"<<std::endl;

            //tm.unlock();
        }
        else
        {
            std::cout <<"failed!"<<std::endl;
        }
    }

    prom.set_value();
    return 0;
};

int main()
{
    std::thread t(work);
    std::this_thread::sleep_for(10s);
    exits=true;
    f.get();
    std::cout << "main exit success."<<std::endl;
    t.join();
    return 1;
};