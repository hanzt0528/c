#include <iostream>
#include <string>

#include <vector>
#include <memory>
void gprint() noexcept(true)
{
    std::cout << "1"<<std::endl;
}


int g_c = 0;
int g_m = 0;
class A
{
    public:
    void print()noexcept
    {
        gprint();
        std::cout << "A.1"<<std::endl;
    };
    A()
    {

    };
    A(const A& a)
    {
        std::cout <<"call copy construction " <<g_c++<<std::endl;
    };
    //A(A&& other)noexcept
    A(A&& other)
    {
        std::cout <<"call move construction "<<g_m++<<std::endl;
    };
};

int main()
{
    std::vector<std::shared_ptr<A>>  vec;
 

    for(int i = 0; i <  20; i ++)
    {
        std::cout << "i = "<<i<<std::endl;
        std::shared_ptr<A> a = std::make_shared<A>();
        vec.push_back(a);
    }

    vec[0]->print();
    
    return 0;
}