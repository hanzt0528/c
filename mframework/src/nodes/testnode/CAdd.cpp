#include "CAdd.h"

#define TAG "CAdd"

CAdd::CAdd():CUnknown("CAdd",nullptr)
{
    LogD("CAdd","CAdd()  this: %p\n",this);
}

CAdd::~CAdd()
{
    LogD(TAG,"~CAdd()  this: %p\n",this);
}


 LONG CAdd::NonDelegatingQueryInterface(const IID& in_rsIID, void **out_ppv) 
{
   if( in_rsIID == IID_IAdd )
   {
     IAdd *pObject = nullptr;
     pObject =  ( IAdd * )this;
     *out_ppv = pObject;
     pObject->AddRef();
     return NOERROR;
   }
   else
   {
      return CUnknown::NonDelegatingQueryInterface(in_rsIID, out_ppv);
   }
}

int CAdd::add(int x, int y)
{
    return x + y;
}
