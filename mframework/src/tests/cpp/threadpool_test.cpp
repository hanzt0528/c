// #include "threadpool.h"
// #include "threadpool2.h"
// #include "threadpool3.h"
//#include "threadpool4.h"
//#include "threadpool5.h"
//#include "threadpool18.h"
//#include "threadpool19.h"
//#include "threadpool20.h"
//#include "threadpool20.h"
#include "threadpool21.h"
//#include "threadpool22.h"
#include <iostream>

std::string  test()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "test!" << std::endl;

    return "100";
};

class A
{
    public:
    template<typename T>
    T sum(T a,T b)
    {
        return a+b;
    }
};

// g++ threadpool_test.cpp
int main(int argc, char *argv[])
{
    float ft = 1e-5f;

    std::cout << "ft = " <<ft<< std::endl;
    std::cout << "hello!" << std::endl;

    fprintf(stderr,"ok\n");


    ThreadPool pool(5);

    auto result = pool.enqueue([](int answer)
                               {
                                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                                return answer; 
                                },
                               42);

    auto result2 = pool.enqueue([](int answer)
                               {
                                 std::this_thread::sleep_for(std::chrono::milliseconds(2000)); 
                                return answer; },
                               43);


    auto result3 = pool.enqueue(test);

    std::cout << result.get() << std::endl;
    std::cout << result2.get() << std::endl;
    std::cout << result3.get() << std::endl;

    A a;
    auto sum = a.sum<int>(1.0,1.0);
    std::cout << "sum="<<sum << std::endl;

    return 0;
}