#include <iostream>
#include <memory>

void pass_up(std::unique_ptr<int> up)
{
    std::cout << "In pass_up:"<<*up<<std::endl;
}

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
    auto up = std::make_unique<int>(100);
    
    pass_up(std::move(up));

   return 0;
}