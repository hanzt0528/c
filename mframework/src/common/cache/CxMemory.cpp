#include "CxMemory.h"

#define TAG "CxMemory"

CxMemory::CxMemory():CUnknown("CxMemory",nullptr),
		     m_pBuffer(nullptr),
		     m_ulBufferSize(0)
{
    LogD("CxMemory","CxMemory()  this: %p\n",this);
}

CxMemory::~CxMemory()
{
    LogD(TAG,"~CxMemory()  this: %p\n",this);
}


 ULONG CxMemory::NonDelegatingQueryInterface(const IID& in_rsIID, void **out_ppv) 
{
   if( in_rsIID == IID_IxMemory )
   {
     IxMemory *pObject = nullptr;
     pObject =  ( IxMemory * )this;
     *out_ppv = pObject;
     pObject->AddRef();
     return NOERROR;
   }
   else
   {
      return CUnknown::NonDelegatingQueryInterface(in_rsIID, out_ppv);
   }
}

HRESULT   CxMemory::GetBuffer( unsigned char ** ppBuffer )
{

   HRESULT hrs = NOERROR ; 

   if( m_pBuffer == NULL )
   {
      *ppBuffer = NULL ;

      hrs = NS_E_NOT_INITIALIZED ;

      return hrs ;
   }

   *ppBuffer = m_pBuffer ; 

   return hrs ;
   
}

HRESULT   CxMemory::Alloc( unsigned long in_ulSize )
{
  HRESULT hr = NOERROR;

  LogD(TAG,"CxMemory::Alloc  this: %p,in_ulSize = %ld\n",this,in_ulSize);

  if(m_pBuffer != nullptr)
    {
      hr = NS_E_ALREADY_IN_USE;
       LogD(TAG,"CxMemory::Alloc this memory already alloc!\n");
      return hr;
    }

   unsigned long ulMega = 1024 *1024 ;

   if( ( in_ulSize % ulMega ) != 0 )
   {
      in_ulSize = ( in_ulSize / ulMega + 1 ) *ulMega ;
   }

   
   m_pBuffer = ( unsigned char* )malloc(in_ulSize);

   
   if( m_pBuffer == NULL )
   {

       LogD(TAG,"CxMemory::Alloc  malloc Failed!\n");

       hr = NS_E_ALLOC_MEMORY_FAILED;

      return hr;
   }


 
   //log memory information
    LogD(TAG,"CxMemory::Alloc  malloc success,sizeinbytes = %d!\n",in_ulSize);


   m_ulBufferSize = in_ulSize ;

  
  return hr;
}

HRESULT  CxMemory::GetSize( unsigned long * out_pulSize )
{
 HRESULT hrs = NOERROR ;

   if( m_pBuffer == nullptr )
   {

      *out_pulSize = 0 ;

      hrs = NS_E_NOT_INITIALIZED ;

      return hrs ;
   }

   *out_pulSize = m_ulBufferSize ;

   return hrs ;
}
