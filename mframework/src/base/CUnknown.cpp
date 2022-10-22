#include "../../include/base/CUnknown.h"

#define TAG "CUnknown"

//-----------------------------------------------------------------------
// constructor
//-----------------------------------------------------------------------
CUnknown::CUnknown(char *in_pszName,
                   IUnknown  *in_pIUnk) 
  :// CNsBaseObject(in_pwszName),
                       m_ulRef(0),
                       m_pkIUnknown(in_pIUnk != 0 ? in_pIUnk : reinterpret_cast<IUnknown *>( static_cast<INonDelegatingUnknown*>(this) ))

{
}

CUnknown::~CUnknown()
{
}


//-----------------------------------------------------------------------
// NonDelegatingQueryInterface
//-----------------------------------------------------------------------
unsigned long  CUnknown::NonDelegatingQueryInterface(const IID& in_rsIID,
                                                     void **out_ppv)
{
#ifdef _DEBUG
   if(out_ppv == NULL) 
      return E_POINTER;
#endif

   //
   // We know only about IUnknown
   //
   if (in_rsIID == IID_IUnknown) 
   {
     IUnknown *pUnknown =  (IUnknown *) (INonDelegatingUnknown*) this;
     *out_ppv =pUnknown;
     pUnknown->AddRef();
      return S_OK;
   } 
   else 
   {
      *out_ppv = nullptr;
      return E_NOINTERFACE;
   }
}

//-----------------------------------------------------------------------
// NonDelegatingAddRef
//-----------------------------------------------------------------------
unsigned long   CUnknown::NonDelegatingAddRef()
{

   LogD(TAG,"enter NonDelegatingAddRef");
   //InterlockedIncrement(&m_lRef);
   m_ulRef++;
   return m_ulRef>1?m_ulRef:1;
}

//-----------------------------------------------------------------------
// NonDelegatingRelease
//-----------------------------------------------------------------------
unsigned long  CUnknown::NonDelegatingRelease()
{

   LogD(TAG,"enter NonDelegatingRelease");
   //
   // If the reference count drops to zero delete ourselves
   //

   //long lRef = InterlockedDecrement(&m_lRef);

   m_ulRef--;
   long lRef = m_ulRef;
   //ASSERT(lRef >= 0);

   if(lRef == 0) 
   {
      // COM rules say we must protect against re-entrancy.
      // If we are an aggregator and we hold our own interfaces
      // on the aggregatee, the QI for these interfaces will
      // addref ourselves. So after doing the QI we must release
      // a ref count on ourselves. Then, before releasing the
      // private interface, we must addref ourselves. When we do
      // this from the destructor here it will result in the ref
      // count going to 1 and then back to 0 causing us to
      // re-enter the destructor. Hence we add an extra refcount here
      // once we know we will delete the object.
      // for an example aggregator see filgraph\distrib.cpp.

      //InterlockedIncrement(&m_lRef);

     m_ulRef ++;
      delete this;
      return 0;
   } 
   else 
   {
      //////////////////////////////////////////////////////////
      // If we return m_lRef , it's not good for pool element.
      // This is to fix those pure virtual function call 
      // Please check yufei's email sent to SwDevList for more details.
     return lRef>1?lRef:1;
   }
}

