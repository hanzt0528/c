#include <iostream>
#include <string>

#include <vector>
#include <memory>


const int imag(const double &im) const;
double imag(const double im);
int main()
{
    std::cout << "sizeof(double) = "<<sizeof(double)<<std::endl;    
    std::cout << "sizeof(float) = "<<sizeof(float)<<std::endl;  
    std::cout << "sizeof(long int) = "<<sizeof(long int)<<std::endl; 
    std::cout << "sizeof(int) = "<<sizeof(int)<<std::endl; 
    std::cout << "sizeof(int8_t) = "<<sizeof(int8_t)<<std::endl; 
     std::cout << "sizeof(uint8_t) = "<<sizeof(uint8_t)<<std::endl; 
    std::cout << "sizeof(int16_t) = "<<sizeof(int16_t)<<std::endl;  
    std::cout << "sizeof(uint16_t) = "<<sizeof(uint16_t)<<std::endl;  
    std::cout << "sizeof(uint32_t) = "<<sizeof(uint32_t)<<std::endl;  
    std::cout << "sizeof(uint64_t) = "<<sizeof(uint64_t)<<std::endl;  
    std::cout << "sizeof(short int) = "<<sizeof(short int)<<std::endl; 

    std::cout << imag(1)<<std::endl;
    return 0;
}


const int imag(const double &im) const
{
    return 1;
}

double  imag(const double im)
{
    return 2;
}