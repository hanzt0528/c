#include <iostream>
#include"../../../include/base/util.h"
#include"../../../include/base/IClassFactory.h"
#include"../../../include/base/IUnknown.h"
#include "../../../include/common/IxMemory.h"

#include <dlfcn.h>

using namespace std;

#define TAG "main"
int main()
{
  HRESULT hr = NOERROR;
    void* pHandle;
     LogD("main","in");
     char *pLibName = "../lib/libcache.so";
      pHandle = dlopen("../lib/libcache.so",RTLD_LAZY);
    if(!pHandle)
    {
        LogE(TAG,"Load lib %s Exception: %s\n",pLibName,dlerror());
        exit(EXIT_FAILURE);
    }
    
    LogD(TAG,"dlopen lib %s successful, handle: %p\n",pLibName,pHandle);
    
    IUnknown* (*pDllGetClassFactory)( const IID &in_rsIID, void **ppvI) = nullptr;
    char* error = nullptr;
    *(void**)(&pDllGetClassFactory) = dlsym(pHandle, "DllGetClassFactory");
    if ((error = dlerror()) != nullptr)
    {
        LogE(TAG,"dlsym find DllGetClassObject Exception: %s\n",error);
        return 0;
    }
    LogD(TAG,"dlsym find DllGetClassObject successful");
    IClassFactory* pClsFactory = nullptr;
    IUnknown* pUnknown = (*pDllGetClassFactory)(IID_ICLSFACTORY,(void**)&pClsFactory);
    if(!pUnknown) return 0;
    if(pClsFactory == nullptr)
    {
        LogE(TAG,"QueryInterface IClassFactory failed!");
        //创建类厂对象时，查询类厂接口失败，再次查询一次
        LONG hr = pUnknown->QueryInterface(IID_ICLSFACTORY,(void**)&pClsFactory);
        if(hr == E_NOINTERFACE)
        {
            pUnknown->Release();
            return 0;
        }
        else if(hr == S_OK)
            pUnknown->Release();
    }
    LogD(TAG,"Get an Operator IClassFactory Pointer successful");
    TNsSmartPtr<IxMemory> pObject = nullptr;
    pClsFactory->CreateInstance(IID_IxMemory,(void**)&pObject);
   
    if(pObject != nullptr)
      {
	 LogD(TAG,"CreateInstance by IID_IxMemory successful");
      }

     hr =  pObject->Alloc(1024*1024);
     unsigned long ulSize = 0;
     hr = pObject->GetSize(&ulSize);
				
    cout<<" alloc size =  " << ulSize <<endl;
  
    return 0;
}
