// #include "threadpool.h"
// #include "threadpool2.h"
// #include "threadpool3.h"
//#include "threadpool4.h"
#include "threadpool5.h"
#include <iostream>

void test()
{
    std::cout << "test!" << std::endl;
};

// g++ threadpool_test.cpp
int main(int argc, char *argv[])
{
    std::cout << "hello!" << std::endl;

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

    return 0;
}