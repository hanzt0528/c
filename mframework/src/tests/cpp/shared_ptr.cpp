#include <iostream>
#include <memory>
#include <vector>
class A
{
    public:
    A(){};
    ~A(){
        std::cout << "~A()"<<std::endl;
    };

    int i{100};

    void print(){std::cout << "print. i = "<<i <<std::endl;};
};

class B
{
    public:
    B(int i,int k){};
    ~B(){
        std::cout << "~A()"<<std::endl;
    };

    int print(){std::cout << "print."<<std::endl; return 100;};
};

void close_file(FILE *fp)
{
    if(fp == nullptr) return;
    fclose(fp);
    std::cout <<"file closed."<<std::endl;
}


class C;
std::vector<std::shared_ptr<C>> processedC;
class C:public std::enable_shared_from_this<C>{
public:
    ~C()
    {
        std::cout <<"~C()"<<std::endl;
    };
    template <typename ... Ts>
    static std::shared_ptr<C> create(Ts&&... params)
    {
        return std::make_shared<C>(params...);
    };

    void process()
    {
        processedC.emplace_back(shared_from_this());
    }

    public:
    int i{2000};
    void print(){
        std::cout << "print "<< i <<std::endl;
    };
};
int main3(int argc,char* argv[])
{
    auto c = C::create();
    c->process();

    return 0;
};

template<class Derived>
struct Base {
    void name(){
        (static_cast<Derived*>(this))->impl();
    }
};

struct D1:public Base<D1>
{
    void impl()
    {
        std::cout <<"D1::impl()"<<std::endl;
    };
};

struct D2:public Base<D2>
{
    void impl()
    {
        std::cout <<"D2::impl()"<<std::endl;
    };
};

int main4(int argc,char* argv[])
{
    D1 d1;d1.name();
    D2 d2;d2.name();

    return 0;
};

class Widget{
    public:
    explicit Widget(int i){
        this->a=i;
    };
    int a;

};

void printWidget(std::weak_ptr<Widget> &wpw)
{
    auto spw = wpw.lock();
    
    std::cout << "==="<<__FUNCTION__<<"==="<<std::endl;
    if(spw)
    {
        std::cout << "widget->a = "<<spw->a<<std::endl;
    }else{
        std::cout << "spw is nullptr"<<std::endl;
    }
};
int main(int argc,char* argv[])
{
    auto spw = std::make_shared<Widget>(10);
    std::weak_ptr<Widget> wpw(spw);
    printWidget(wpw);
    spw=nullptr;
    if(wpw.expired()){
        std::cout << "expired" << std::endl;
    }
    printWidget(wpw);
    try{
        std::shared_ptr<Widget> spw3(wpw);
    } catch(const std::exception &ex)
    {
        std::cout <<"exception:"<<ex.what()<<std::endl;
    }
    return 0;
};

int main1(int argc,char* argv[])
{
    std::cout << "main" << std::endl;

    A * ap = new A();
    std::shared_ptr<A> sp(ap);
    sp->print();

    std::cout << "sp = "<<sp.get() <<std::endl;

    std::cout << "ap = "<<ap<<std::endl;

    std::shared_ptr<A> sp2 = sp;
    std::cout << "sp.use_count = "<< sp.use_count()<<std::endl;

    sp.reset();
    std::cout << "sp.use_count = "<< sp.use_count()<<std::endl;
    
    std::cout << "sp.reset"<<std::endl;

    std::shared_ptr<B> p = std::make_shared<B>(1,2);

    std::shared_ptr<int> pi = std::make_shared<int>(100);

    std::cout << pi<<std::endl;
    std::cout << pi.get()<<std::endl;

    //costum delete function
    FILE *fp = fopen("1.txe","w");
    std::shared_ptr<FILE> pf{fp,close_file};

    auto loggingDel = [](A*a){
        std::cout << "call loggingDel"<<std::endl;
        if (a != nullptr)
            delete a;
    };

        auto loggingDel2 = [](A*a){
        std::cout << "call loggingDel2"<<std::endl;
        if (a != nullptr)
            delete a;
    };

    std::shared_ptr<A> a(new A,loggingDel);
    std::unique_ptr<A,decltype(loggingDel2)> b(new A,loggingDel2);

    std::shared_ptr<A> map = std::move(b);
    std::cout << "map use_count = "<<map.use_count()<<std::endl;
    std::shared_ptr<A> map2 = map;
    std::cout << "call reset 1 use_count = "<<map.use_count()<<std::endl;

    map.reset();
    std::cout << "call reset 2 use_count = "<<map.use_count()<<std::endl;
    map2->print();


    std::shared_ptr<C>  c = C::create();

    c->print();


    return 0;
}