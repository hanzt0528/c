#include <iostream>
#include <thread>
#include <future>
// g++ -pthread async.cpp

// todo...

void hello(const char *message)
{
    std::cout << message << std::flush;
}
int main()
{
    std::async(std::launch::async,[](const char *message){
        std::cout <<message<<std::ends;
    },"Hello,");

    // std::future<void >ret = std::async(std::launch::deferred,hello, "Hello,");
    // ret.get();
    std::cout << "World!" << std::endl;

    
    return 1;
}