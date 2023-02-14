#include "../include/iter.hpp"
#include <array> 

void call(int elem)
{
    while (elem)
    {
        std::cout << "Call function" << std::endl;
        elem--;
    }
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4};
    int len = std::end(arr)- std::begin(arr);

    ::iter(arr, len, &call);
    
    return 0;
}