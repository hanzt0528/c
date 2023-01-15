#include <iostream>
#include <string>


int main()
{
    int a = 10;
    int &a1 = a;

    int &&r = std::move(a);
    a1=100;
    
    int r2 = std::move(r);

    const int ci = r;


    std::cout << r <<std::endl;


    return 0;
}