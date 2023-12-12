#include <iostream>

#include<bitset>
static inline  uint32_t fp32_to_bits(float f)
{
    union
    {
        float as_value;
        uint32_t as_bits;
    }fp32;

    fp32.as_value =f;

    return fp32.as_bits;
    
}

#define GGML_PAD(x,n) ( ((x) + (n)-1) & ~((n)-1))


int main(int argc, const char** argv) {
    std::cout << "hello!"<<std::endl;
    std::cout <<fp32_to_bits(1.0)<<std::endl;
    std::cout <<std::bitset<sizeof(uint32_t)*8>(fp32_to_bits(12.5))<<std::endl;

    std::cout << "GGML_PAD(400,16) = "<<GGML_PAD(400,16)<<std::endl;

    std::cout <<std::bitset<sizeof(uint32_t)*8>(401)<<std::endl;
    std::cout <<std::bitset<sizeof(uint32_t)*8>(401+16-1)<<std::endl;
    std::cout <<std::bitset<sizeof(uint32_t)*8>( ~((16)-1))<<std::endl;
    std::cout <<std::bitset<sizeof(uint32_t)*8>( GGML_PAD(401,16) )<<std::endl;


    return 0;
}