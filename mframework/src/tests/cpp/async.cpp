#include <iostream>
#include <thread>
#include <future>
//g++ -pthread async.cpp
int main()
{
    std::async(std::launch::async,[](const char *message){
        std::cout <<message;
    },"Hello,");
    std::cout << "World!"<<std::endl;
    return 1;    
}