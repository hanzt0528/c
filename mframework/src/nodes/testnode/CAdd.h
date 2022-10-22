#ifndef COPERATOR_H
#define COPERATOR_H

#include "../../../include/nodes/IAdd.h"
#include "../../../include/base/CUnknown.h"


class CAdd : public IAdd,
	     public CUnknown
{
public:
    CAdd();
    ~CAdd();
    NSDECLARE_IUNKNOWN
  public:
    //IUnknown interface
  virtual unsigned long  NonDelegatingQueryInterface(const IID& in_rsIID, void **out_ppv);
    //IAdd interface
    virtual int add(int x,int y);
};

#endif // COPERATOR_H
