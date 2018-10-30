#include <string.h>
#include <stdarg.h>
#include "../../include/base/util.h"
using namespace std;

bool operator==(const IID& guid1, const IID& guid2)
{
    if(guid1.Data1 != guid2.Data1)
        return false;
    if(guid1.Data2 != guid2.Data2)
        return false;
    if(guid1.Data3 != guid2.Data3)
        return false;

    for(int i = 0; i < 8; i++)
    {
        if(guid1.Data4[i] != guid2.Data4[i])
            return false;
    }
    return true;
}

void LogD(const char* TAG,const char* format, ...)
{
    if(format != nullptr)
    {
        if(strchr(format,'%'))
        {
            va_list ap;
            va_start(ap,format);

            if(strcmp(TAG,"") == 0)
            {
                cout << "";
            }
            else
            {
                printf("%s: ",TAG);
            }
            vprintf(format,ap);
            va_end(ap);
        }
        else
        {
            if(strcmp(TAG,"") == 0)
            {
                cout << "\n";
            }
            else
            {
                cout << TAG << " : " << format << endl;
            }
        }
    }
    else
    {
        cout << TAG << endl;
    }
}

void LogE(const char* TAG,const char* format, ...)
{
    if(format != nullptr)
    {
        if(strchr(format,'%'))
        {
            va_list ap;
            va_start(ap,format);
            if(strcmp(TAG,"") == 0)
            {
                cout << "";
            }
            else
            {
                fprintf(stderr,"%s: ",TAG);
            }
            vfprintf(stderr,format,ap);
            va_end(ap);
        }
        else
        {
        //    fprintf(stderr,"%s : msg: %s\n",TAG,format);
            if(strcmp(TAG,"") == 0)
            {
                cout << "\n";
            }
            else
            {
                cerr << TAG << " : " << format << endl;
            }
        }
    }
    else
    {
        cout << TAG << endl;
    }
}
