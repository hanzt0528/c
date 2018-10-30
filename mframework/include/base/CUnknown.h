#ifndef CUNKNOWN_H
#define CUNKNOWN_H


#include "IUnknown.h"

//Implement base interface IUnknown
class CUnknown : public INonDelegatingUnknown
{

private:
  IUnknown* m_pkIUnknown;

protected:
   volatile long m_ulRef;
public:
    CUnknown(char   *in_pszName,
              IUnknown  *in_pIUnk);
    ~CUnknown();
public:

   IUnknown* GetOwner()
   {
      return m_pkIUnknown;
   }
    virtual LONG  __stdcall NonDelegatingQueryInterface(const IID& in_rsIID, void** ppvI);
    virtual ULONG __stdcall NonDelegatingAddRef();
    virtual ULONG __stdcall NonDelegatingRelease(); 

};


#endif // CUNKNOWN_H
