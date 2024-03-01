#include <functional>
#include <iostream>
#include <iomanip>
#define add(T) _ADD_IMPL_##T

#define ADD_IMPL(T) \
T _ADD_IMPL_##T(T a,T b){ \
    return a+b; \
}



ADD_IMPL(int);
ADD_IMPL(float);


int main()
{

    int sum_micro = add(int)(1,2);
    std::cout << "sum_micro = "<<sum_micro<<std::endl;
    float sum_micro_f = add(float)(1.0,2.0);

    std::cout << "sum_micro_f = "<< std::setprecision(5) <<sum_micro_f<<std::endl;
    return 0;
}

