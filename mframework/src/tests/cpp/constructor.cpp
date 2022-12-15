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

    //copy assignment operator.
  
    A& operator=(const A& other){
        std::cout << "copy assignment operator."<<std::endl;
        if(this != &other){
            if(data != nullptr) delete []data;
            length = other.length;
            data = new int[other.length];
            std::copy(other.data,other.data+other.length,data);
        }

        return *this;
    };

    //move constructor
    A(A&& other)
    :length(0),
    data(nullptr){
        std::cout << "move constructor."<<std::endl;
        length = other.length;
        data = other.data;
        other.length = 0; 
        other.data = nullptr;
    };

    //move assignment operator
    A& operator=(A&&other){
        std::cout << "move assignment operator."<<std::endl;
        if(this != &other){
            length = other.length;
            data = other.data;
            other.length = 0;
            other.data = nullptr;
        }
        return *this;
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
    a1.data = new int[2];
    a1.length = 2;

    A a2;
    //a2 = std::move(a1);
    A a3;
    a3 = std::move(a1);

    std::shared_ptr<A> pa;

    getA(pa);

    std::cout << "pa use_count = "<<pa.use_count()<<std::endl;

    std::vector<std::shared_ptr<A> > as;

    as.push_back(pa);
    std::cout << "pa use_count = "<<pa.use_count()<<std::endl;
    as.clear();
    std::cout << "pa use_count = "<<pa.use_count()<<std::endl;
    
    std::weak_ptr<A> wp(pa);

    std::cout << "pa use_count = "<<pa.use_count()<<std::endl;


   return 0;
}