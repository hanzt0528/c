#include"delayed_thread.h"
#include <iostream>
#include <chrono>
using namespace std::chrono_literals;
void work()
{
    std::cout << " work " << std::endl;
}

int main()
{
    DelayedThread t(&work,DelayedThread::destruction_action::join);

    std::cout << " waiting... "<< std::endl;
    std::this_thread::sleep_for(3s);
    t.execute(); 
    return 0;
}