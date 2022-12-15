#include <iostream>
#include <future>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex mtx;
std::condition_variable cv;
void task(int a,std::future<int>& b,std::promise<int> &ret)
{
    int ret_a = a*a;
    int ret_b = b.get()+12;

    ret.set_value(ret_a+ret_b);


}
int main()
{

    int ret = 0;
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::promise<int> p_in;
    std::future<int> f_in = p_in.get_future();

    std::thread t(task,1,std::ref(f_in),std::ref(p));
    
    p_in.set_value(2);

    ret = f.get();

    std::cout << "ret = "<<ret<<std::endl;

    t.join();
}