#ifndef COPERATORFACTORY_H
#define COPERATORFACTORY_H

#include "../../../include/base/IClassFactory.h"
#include "CxMemory.h"

class CCacheClassFactory : public IClassFactory
{
public:
    CCacheClassFactory();
    ~CCacheClassFactory();

private:
    virtual LONG  QueryInterface(const IID& in_rsIID, void** ppvI);
    virtual ULONG AddRef();
    virtual ULONG Release();
    virtual IUnknown* CreateInstance(const IID& in_rsIID,void**ppvI);


    ULONG m_ulRef;
};

#ifdef __cplusplus
extern "C"
{
#endif

IUnknown* DllGetClassFactory(const IID &in_rsIID, void **ppvI);

#ifdef __cplusplus
}
#endif

#endif // COPERATORFACTORY_H
