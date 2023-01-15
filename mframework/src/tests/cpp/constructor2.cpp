#include <iostream>
#include <memory>
#include <vector>
class A
{
    public:
    A(){
        data=nullptr;
        length = 0;
    };
    ~A(){};

    //copy constructor.
    A(const A& other)
    :length(other.length),
    data(new int[other.length]){
        std::cout << "copy constructor" << std::endl;
        std::copy(other.data,other.data+other.length,data);
    };

    public:
    int *data;
    int length;
};

void getA(std::shared_ptr<A> &pA)
{
    std::shared_ptr<A> a = std::make_shared<A>();

    pA = a;
}

int main(int argc,char* argv[])
{
    A a1;

    A a2 = std::move(a1);
  

   return 0;
}