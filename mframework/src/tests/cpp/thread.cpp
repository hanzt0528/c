#include <iostream>
#include <memory>
#include <thread>
void loop()
{
    std::cout<<"loop"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
};

class A
{
    public:
    A(){};
    ~A(){};

    static int loop( A* a)
    {
        a->print();
        std::cout<<"A::loop"<<std::endl;
        return 1;
    };

    void run(){
        std::thread t(A::loop,this);

        t.join();
    };

    void print()
    {
        std::cout <<"A::print\n";
    };
};

int main(int argc,char* argv[])
{
   std::thread t1(loop);

   std::thread t([&]{
        std::cout<<"loop"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
   });

   t.join();

   std::cout << "join"<<std::endl;

   A a;
   a.run();

   return 0;
}