#ifndef XERRORS_H
#define XERRORS_H

#define S_OK  0
#define HRESULT long
#define NOERROR 0
#define NS_NOERROR 0
#define E_POINTER -1
#define E_NOINTERFACE -1


#define X_MAKE_HRESULT(sev,fac,code) \
    ((HRESULT) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )

#define _FACNSPG_X   0x888 // 0x999
#define X_MAKE_NSHRESULTERROR(code) X_MAKE_HRESULT( 1, _FACNSPG_X, code )
#define X_MAKE_NSHRESULTWARNING(code) X_MAKE_HRESULT( 0, _FACNSPG_X, code )


#define NS_E_ALLOC_MEMORY_FAILED                               X_MAKE_NSHRESULTERROR (0x8045)  // 

#define NS_E_ALREADY_IN_USE                                    X_MAKE_NSHRESULTERROR (0x8046)  // Failed the module/object is already in use.

#define NS_E_NOT_INITIALIZED                                   X_MAKE_NSHRESULTERROR (0x8047)  // Failed because the module/object is not initialized.


#endif // XERRORS_H
