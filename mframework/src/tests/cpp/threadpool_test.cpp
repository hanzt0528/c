// #include "threadpool.h"
// #include "threadpool2.h"
#include "threadpool3.h"
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
                               { return answer; },
                               42);

    std::cout << result.get() << std::endl;

    auto result2 = pool.enqueue(test);

    return 0;
}