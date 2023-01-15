#include <iostream>
#include <memory>
#include <string.h>
#include <vector>


class CString
{
public:
    explicit CString(int size)
    {
        size_ = size;
        pstr_ = (char *)malloc(size + 1);
        memset(pstr_, 0, size + 1);
        std::cout << " CString(int size) call" << std::endl;
    };

    void print_size()
    {
        std::cout << "size = " << size_ << std::endl;
    };

private:
    char *pstr_;
    size_t size_;
};

int main()
{
    // CString s = 12;//error bucause explicit;
    // CString s(12);//ok
    CString s{12}; // ok
    s.print_size();

    return 0;
}