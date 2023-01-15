#include <iostream>


class ABC
{

};

class ABCD:public ABC
{

};
auto add(double a,double b)->double
{
    return a+b;
}

int main()
{
    ABCD c;
    std::cout <<"add = "<< typeid(add(1.0,2.0)).name()<<std::endl;
    std::cout <<"ABC type = "<< typeid(c).name()<<std::endl;


    if(typeid(c) == typeid(ABCD))
    {
        std::cout << "same"<<std::endl;
    }

    return 0;
}