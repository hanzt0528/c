#ifndef CXMEMORY_H
#define CXMEMORY_H

#include "../../../include/common/IxMemory.h"
#include "../../../include/base/CUnknown.h"



class CxMemory : public IxMemory,
	     public CUnknown
{
public:
    CxMemory();
    ~CxMemory();
  NSDECLARE_IUNKNOWN
public:
    //IUnknown interface
  virtual LONG  __stdcall NonDelegatingQueryInterface(const IID& in_rsIID, void **out_ppv);
    //IxMemory interface
   virtual HRESULT __stdcall GetBuffer( unsigned char ** ppBuffer );

   virtual HRESULT __stdcall Alloc( unsigned long in_ulSize );

   virtual HRESULT __stdcall GetSize( unsigned long * out_pulSize );
protected:
  unsigned char *m_pBuffer;
  unsigned long m_ulBufferSize;

};

#endif // CXMEMORY_H
