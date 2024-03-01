#include <iostream>


void bubblesort1(int array[],int n)
{

    int temp = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < (n-i); j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {1,4,5,8,9,0,};
    constexpr int n = sizeof(a)/sizeof(int);

    std::cout<<"orig:"<<std::endl;

    for(int i = 0; i < n; i++)
    {
        std::cout << a[i]<<std::endl;
    }

    bubblesort1(a,n);

    std::cout<<"\n result :"<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cout << a[i]<<std::endl;
    }

    return 0;
}