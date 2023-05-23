#include "../include/iter.hpp"
#include <array> 

int main()
{
    int arr[] = {0, 1, 2, 3, 4};
    int len = std::end(arr) - std::begin(arr);

    ::iter(arr, len, &call);
    
    return 0;
}