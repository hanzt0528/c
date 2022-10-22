#ifndef IUNKNOWN_H
#define IUNKNOWN_H

#include "util.h"
#include "type.h"
#include "xerrors.h"
#include "TNsSmartPtr.h"
interface IUnknown
{
public:
    virtual LONG   QueryInterface(const IID& in_rsIID, void** ppvI) = 0;
    virtual ULONG  AddRef() = 0;
    virtual ULONG  Release() = 0;

};


interface INonDelegatingUnknown
{
public:
    virtual unsigned long   NonDelegatingQueryInterface(const IID& in_rsIID, void** ppvI) = 0;
    virtual ULONG  NonDelegatingAddRef() = 0;
    virtual ULONG  NonDelegatingRelease() = 0;

};


#ifndef NSDECLARE_IUNKNOWN
#define NSDECLARE_IUNKNOWN									\
    inline virtual HRESULT  QueryInterface(const IID& in_rsIID, void **ppv) {      \
        return GetOwner()->QueryInterface(in_rsIID,ppv);            \
    };                                                          \
    inline virtual unsigned long  AddRef() {              \
        return GetOwner()->AddRef();                            \
    };                                                          \
    inline virtual unsigned long  Release() {             \
        return GetOwner()->Release();                           \
    };                                                          
#endif

extern "C"
{
    const IID IID_IUnknown = {0x32bb8324, 0xb41b, 0x11cf,{0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
}

#endif // IUNKNOWN_H
