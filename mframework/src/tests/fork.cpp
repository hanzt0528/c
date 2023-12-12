#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
using namespace std;

int main()
{

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

        for(;;)
        {
            char *p = new char[1024*1024*10];
        }

        for(int i = 0; i < 3; i++)
        {
            std::cout << "Hello from Child Process!"<<std::endl;

            if(i == 2)
            {
                i = i/0;
            }
            sleep(2);
        }

        exit(EXIT_SUCCESS);

    }

    return 0;
}