#include <iostream>
#include <future>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex mtx;
std::condition_variable cv;
void task(int a,std::shared_future<int> b,std::promise<int> &ret)
{
    int ret_a = a*a;
    int ret_b = b.get()+12;

    ret.set_value(ret_a+ret_b);


}
int main()
{

    int ret = 0;
    std::promise<int> p;
    std::promise<int> p2;
    std::future<int> f = p.get_future();

    std::promise<int> p_in;

    std::future<int> f_in = p_in.get_future();
    std::shared_future<int> s_f_in=f_in.share();

    std::thread t(task,1,s_f_in,std::ref(p));
    std::thread t2(task,1,s_f_in,std::ref(p2));
    
    p_in.set_value(2);

    ret = f.get();

    std::cout << "ret = "<<ret<<std::endl;

    t.join();
    t2.join();
}