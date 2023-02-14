#ifndef ITER_H

#define ITER_H
#include <iostream>
#include <array> 

    template <typename T>
    void iter(T array[], T arr_len, T (func)(T))
    {
        std::cout << "The address of the array: " << &array << " | ";
        std::cout << "The length of the array: " << arr_len << " | " << std::endl;
    }

#endif