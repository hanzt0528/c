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

typedef void* HANDLE;

#define interface class



#endif // TYPE_H
