#ifndef _X_MEMORY_H_ 
#define _X_MEMORY_H_  

#include "../base/IUnknown.h"


extern "C"
{
    const IID IID_IxMemory = {0x32bb8329, 0xb41b, 0x11cf,{0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x83}};
}

interface IxMemory : public IUnknown
{
public:
   virtual HRESULT  GetBuffer( unsigned char ** ppBuffer ) = 0;

   virtual HRESULT  Alloc( unsigned long in_ulSize ) = 0;

   virtual HRESULT  GetSize( unsigned long * out_pulSize ) = 0;
};

#endif 

