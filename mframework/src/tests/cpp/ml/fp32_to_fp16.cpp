#include <iostream>

#include<bitset>
#include <math.h>
#if defined(__ARM_NEON) && defined(__CUDACC__)
    typedef half ggml_fp16_t;

#elif defined(__ARM_NEON)
    typedef __fp16 ggml_fp16_t;
#else
    typedef uint16_t ggml_fp16_t;

#endif

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

static inline float fp32_from_bits(uint32_t w)
{
    union{
        uint32_t as_bits;
        float as_value;
    }fp32;

    fp32.as_bits=w;
    return fp32.as_value;
}


static inline ggml_fp16_t ggml_compute_fp32_to_fp16(float f){

#if defined(__STDC_VERSION__) &&(__STDC_VERSION__>=199901L) || defined(__GUNC__) && !defined(__STRICT_ANSI__)
    const float scale_to_inf = 0x1.0p+112f;
    const float scale_to_zero = 0x1.0p-110f;
#else
    const float scale_to_inf = fp32_from_bits(UINT32_C(0x77800000));
    const float scale_to_zero=fp32_from_bits(UINT32_C(0x08800000));
#endif

    // const float scale_to_inf = 0x1.0p+112f;
    // const float scale_to_zero = 0x1.0p-110f;


    // const float scale_to_inf = fp32_from_bits(UINT32_C(0x77800000));
    // const float scale_to_zero=fp32_from_bits(UINT32_C(0x08800000));


    float base = (fabsf(f)*scale_to_inf)*scale_to_zero;
    const uint32_t w = fp32_to_bits(f);
    const uint32_t shl1_w = w + w;
    const uint32_t sign = w & UINT32_C(0x80000000);
    uint32_t bias = shl1_w & UINT32_C(0xFF000000);

    if(bias < UINT32_C(0x71000000)){
        bias = INT32_C(0x71000000);
    }

    base = fp32_from_bits((bias>>1) + UINT32_C(0x07800000)) + base;
    const uint32_t bits = fp32_to_bits(base);
    const uint32_t exp_bits = (bits >>13) & UINT32_C(0x00007C00);
    const uint32_t mantissa_bits = bits &UINT32_C(0x00000FFF);
    const uint32_t nonsign=exp_bits +mantissa_bits;
    return (sign >>16) | (shl1_w > UINT32_C(0xFF000000)? UINT16_C(0x7E00):nonsign );
}

#define GGML_PAD(x,n) ( ((x) + (n)-1) & ~((n)-1))



int main(int argc, const char** argv) {
    std::cout << "hello!"<<std::endl;
    //std::cout <<fp32_to_bits(1.0)<<std::endl;
    std::cout <<std::bitset<sizeof(uint32_t)*8>(fp32_to_bits(9.625))<<std::endl;

    // std::cout << "GGML_PAD(400,16) = "<<GGML_PAD(400,16)<<std::endl;

    // std::cout <<std::bitset<sizeof(uint32_t)*8>(401)<<std::endl;
    // std::cout <<std::bitset<sizeof(uint32_t)*8>(401+16-1)<<std::endl;
    // std::cout <<std::bitset<sizeof(uint32_t)*8>( ~((16)-1))<<std::endl;
    // std::cout <<std::bitset<sizeof(uint32_t)*8>( GGML_PAD(401,16) )<<std::endl;

    // std::cout <<std::bitset<sizeof(uint32_t)*4>(ggml_compute_fp32_to_fp16(0))<<std::endl;

    return 0;
}