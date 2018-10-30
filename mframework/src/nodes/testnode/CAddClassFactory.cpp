#include "CAddClassFactory.h"
#define TAG "CAddClassFactory"
CAddClassFactory::CAddClassFactory()
{
    LogD("CAddClassFactory: ","===CAddClassFactory()===");
}

CAddClassFactory::~CAddClassFactory()
{
    LogD("CAddClassFactory: ","===~CAddClassFactory()===");
}

LONG CAddClassFactory::QueryInterface(const IID &in_rsIID, void **ppvI)
{
    LogD(TAG,"enter QueryInterface");
    if(in_rsIID == IID_ICLSFACTORY)
    {
        LogD(TAG,"Return Pointer to IClassFactory");
        *ppvI = static_cast<IClassFactory*>(this);
    }
    else if(in_rsIID == IID_CLS_IUnknown)
    {
        LogD(TAG,"Return Pointer to IUnknown");
        *ppvI = static_cast<IUnknown*>(this);
    }
    else
    {
        LogD(TAG,"Interface is not surpport!");
        *ppvI = nullptr;
        return E_NOINTERFACE;
    }
    reinterpret_cast<IUnknown*>(*ppvI)->AddRef();

    return S_OK;
}

ULONG CAddClassFactory::AddRef()
{
    //atomic operator in linux
    m_ulRef++;
    LogD(TAG,"AddRef,m_cRef: %d\n",m_ulRef);
    return m_ulRef;
}

ULONG CAddClassFactory::Release()
{
    LogD(TAG,"Release,m_cRef: %d\n",m_ulRef);
    //atomic operator in linux
    if((--m_ulRef) == 0)
    {
        delete this;
        return 0;
    }
    return m_ulRef;
}

IUnknown *CAddClassFactory::CreateInstance(const IID &in_rsIID, void **ppvI)
{
    LogD(TAG,"CreateComInstance start");
    IUnknown* pIUnknown = nullptr;
    IAdd *pIObject = static_cast<CAdd*>(new CAdd());

    pIObject->QueryInterface(IID_IUnknown,(void**)&pIUnknown);
    
    pIUnknown->AddRef();
    LogD(TAG,"COM OBJECT CClass Created successful");
    LONG hr = pIUnknown->QueryInterface(in_rsIID,ppvI);

    if(hr == S_OK)
    {
        pIUnknown->Release();
    }
//    pUnknown = (*g_CoCreate)(iid,ppv);
    LogD(TAG,"CreateComInstance end");

    return pIUnknown;
}

IUnknown* DllGetClassFactory(const IID &in_rsIID, void **ppvI)
{
    LogD(TAG,"enter DllGetClassFactory");

        IUnknown* pI = static_cast<IClassFactory*>(new CAddClassFactory);
        pI->AddRef();
        LogD(TAG,"ClassFactory create successful");
        LONG hr = pI->QueryInterface(in_rsIID,ppvI);
        if(hr == S_OK)
        {
            pI->Release();
        }
        return pI;
}
