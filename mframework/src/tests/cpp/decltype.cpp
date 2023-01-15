#include <iostream>



int main(int argc,char *argv[])
{
    int x=10;
    decltype(x) y = x;

    y = 100;
    std::cout << "x = " <<x<<std::endl;

    return 0;
}