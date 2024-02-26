#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <wait.h>
//#include "get_mem.h"
using namespace std;

int g_cur_pid;
void sighandler(int)
{
    std::cout << "SigHandler!"<<std::endl;

    sleep(3);
    kill(g_cur_pid,SIGKILL);

}

#define MEM_LIM 8*1024*1024



int main()
{

signal(SIGTERM,sighandler);
signal(SIGKILL,sighandler);

g_cur_pid = getpid();

start:
    pid_t childPid= fork();

    if(childPid == -1)
    {
        std::cout << "Failed to create a new process."<<std::endl;
    }
    else if (childPid > 0)
    {
        int parentPid = getpid();
        std::cout << "parentPid:"<<parentPid<<std::endl;
        sleep(5);
        wait(NULL);
        goto start;
        std::cout << "Child Process has finished execution."<<std::endl;

        
    }else
    {
        int childProcessID = getpid();
        std::cout << "childProcessID:"<<childProcessID<<std::endl;

        struct rlimit old_limit;
        struct rlimit64 new_limit;
        getrlimit(RLIMIT_AS,&old_limit);

        std::cout <<"soft virtual memory limit:"<<old_limit.rlim_cur/1024/1024<<std::endl;
        std::cout <<"hard virtual memory limit:"<<old_limit.rlim_max/1204/1024<<std::endl;

        new_limit.rlim_cur = MEM_LIM/2;
        new_limit.rlim_max = MEM_LIM;

        setrlimit64(RLIMIT_AS,&new_limit);

        getrlimit64(RLIMIT_AS,&new_limit);

        std::cout <<"soft virtual memory limit:"<<new_limit.rlim_cur/1024/1024<<std::endl;
        std::cout <<"hard virtual memory limit:"<<new_limit.rlim_max/1204/1024<<std::endl;


        // char * str=  nullptr;
        // try
        // {
        //      str = (char*)malloc(1024*1024);

        //      if(!str)
        //      {
        //         std::cerr <<"error"<<"\n";
        //      }
        // }
        // catch(const std::exception& e)
        // {
        //     std::cerr << e.what() << '\n';
        // }
        

        // for(;;)
        // {
        //     char *p = new char[1024*1024*10];
        // }

        for(int i = 0; i < 3; i++)
        {
            std::cout << "Hello from Child Process!"<<std::endl;

            // if(i == 2)
            // {
            //     i = i/0;
            // }
            sleep(2);
        }

        exit(EXIT_SUCCESS);

    }

    return 0;
}