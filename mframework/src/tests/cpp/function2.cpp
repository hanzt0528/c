#include <functional>
#include <iostream>

#define add(T) _ADD_IMPL_##T

#define ADD_IMPL(T) \
T _ADD_IMPL_##T(T a,T b){ \
    return a+b; \
}



void print_num(int i)
{
    std::cout<<i<<'\n';
}

template<class T>
void t_print_num(T i)
{
    std::cout<<i<<'\n';
}


class A
{
    public:
    int sum(int a,int b)
    {
        return a+b;
    }
};


template<class T>
class B
{
    public:
    T sum(T a,T b)
    {
        return a+b;
    }
};

class C
{
    public:
    template<class T>
    T sum(T a,T b)
    {
        return a+b;
    }
};

ADD_IMPL(int);
ADD_IMPL(float);


int main()
{

    int sum_micro = add(int)(1,2);
    std::cout << "sum_micro = "<<sum_micro<<std::endl;

    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);

    // store a lambda
    std::function<void()> f_display_42 = []{print_num(42);};

    f_display_42();

    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_num,31337);
    f_display_31337();

    std::function<void(std::string)> f_display_t = t_print_num<std::string>;

    f_display_t(std::string("100.0"));

    std::function<int(A,int,int)> sum = &A::sum;

    A a;
    auto s = sum(a,100,200);
    std::cout <<"sum is :"<<s<<std::endl;



    std::function<int(B<int>,int,int)> sum_b = &B<int>::sum;

    B<int> b;
    auto s_b = sum_b(b,100,200);
    std::cout <<"sum is :"<<s_b<<std::endl;



    std::function<std::string(B<std::string>,std::string,std::string)> sum_b_s = &B<std::string>::sum;

    B<std::string> b_s;
    auto s_b_s = sum_b_s(b_s,std::string("100"),std::string("200"));
    std::cout <<"sum is :"<<s_b_s<<std::endl;


    std::function<int(C,int,int)> sum_c=&C::sum<int>;

    C c;

    auto s_c = sum_c(c,100,200);
    std::cout <<"sum is :"<<s_c<<std::endl;

    int res = c.sum<int>(100,200);
    std::cout <<"res is :"<<res<<std::endl;


    return 0;
}

