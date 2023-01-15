#include <iostream>
#include <string>

void print() {}

template <typename T, typename... Types>
void print(T firstArg, Types... args) {
  std::cout << firstArg << '\n'; // print first argument
  print(args...);                // call print() for remaining arguments
}

int main()
{
    print(1,2,3,4,"ct");

    std::string k[] = {"1s","2s","3s","4s","5s"};

    std::cout <<typeid(k).name()<<std::endl;

    for(auto i:k)
    {
        std::cout << i << std::flush;
    }

    std::cout <<std::endl;


    return 0;
}