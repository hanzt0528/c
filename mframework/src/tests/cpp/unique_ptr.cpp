#include <iostream>
#include <memory>

void pass_up(std::unique_ptr<int> up)
{
    std::cout << "In pass_up:"<<*up<<std::endl;
}
int main(int argc,char* argv[])
{
    auto up = std::make_unique<int>(100);
    
    pass_up(std::move(up));

   return 0;
}