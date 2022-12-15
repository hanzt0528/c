#include <iostream>
#include <future>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex mtx;
std::condition_variable cv;
void task(int a,int b,int &ret)
{
    int ret_a = a*a;
    int ret_b = b+12;
    std::unique_lock<std::mutex> lock(mtx);
    ret  = ret_a+ret_b;

    cv.notify_one();
}
int main()
{

    int ret = 0;

    std::thread t(task,1,2,std::ref(ret));
    
    {
    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock);
    std::cout << "ret = "<<ret<<std::endl;
    
    }
    t.join();
}