#include <iostream>
#include <functional>

// g++ -std=c++11 function.cpp
int add(const int a, const int b)
{
    return a + b;
};

class A
{
public:
    int sum(int a, int b)
    {
        return a + b;
    };
};

int main()
{
    std::function<int(int)> fadd(std::bind(&add, std::placeholders::_1, 2));
    auto sum = fadd(1);

    std::cout << "sum is :" << sum << std::endl;
    std::function<int(A&,int,int)> fsum=&A::sum;

    A a;

    sum  = fsum(a,1,2);
    std::cout << "sum is :" << sum << std::endl;
    return 0;
}