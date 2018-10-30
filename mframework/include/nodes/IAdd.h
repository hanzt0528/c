#ifndef IADD_H
#define IADD_H

#include "../base/IUnknown.h"

extern "C"
{
    const IID IID_IAdd = {0x32bb8328, 0xb41b, 0x11cf,{0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
}

interface IAdd : public IUnknown
{
public:
    virtual int add(int x,int y) = 0;
};

#endif // IADD_H
