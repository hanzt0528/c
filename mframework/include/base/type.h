#ifndef TYPE_H
#define TYPE_H

typedef long            LONG;
typedef unsigned long   ULONG;

typedef struct _GUID
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
}GUID;

typedef GUID IID;
typedef GUID CLSID;

#define interface class

#define E_NOINTERFACE -1
#define S_OK  0
#define HRESULT long
#define NOERROR 0
#define E_POINTER -1
#ifndef NSDECLARE_IUNKNOWN
#define NSDECLARE_IUNKNOWN									\
    inline virtual HRESULT __stdcall QueryInterface(const IID& in_rsIID, void **ppv) {      \
        return GetOwner()->QueryInterface(in_rsIID,ppv);            \
    };                                                          \
    inline virtual unsigned long __stdcall AddRef() {              \
        return GetOwner()->AddRef();                            \
    };                                                          \
    inline virtual unsigned long __stdcall Release() {             \
        return GetOwner()->Release();                           \
    };                                                          
#endif


#endif // TYPE_H
