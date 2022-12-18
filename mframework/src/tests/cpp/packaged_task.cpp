#include <iostream>
#include <functional>
#include <future>

int add(const int a, const int b)
{
    return a + b;
};

// g++ -pthread -std=c++11 packaged_task.cpp
int main()
{

    // std::function<int(int)> fadd(std::bind(&add, std::placeholders::_1, 2));

    // auto sum = fadd(1);

    // std::cout << "sum is :" << sum << std::endl;

    std::packaged_task<int()> t(std::bind(add, 1, 2));

    t();
    auto f = t.get_future();
    f.wait();
    std::cout << "sum is :" << f.get() << std::endl;
    return 0;
}