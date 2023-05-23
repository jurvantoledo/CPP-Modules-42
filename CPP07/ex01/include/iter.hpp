#ifndef ITER_H

#define ITER_H
#include <iostream>
#include <array> 

    template <typename T>
    void iter(T arr[], T arr_len, void (*function)(T&))
    {
        std::cout << "The address of the array: " << &arr << " | ";
        std::cout << "The length of the array: " << arr_len << " | " << std::endl;
        for (int i = 0; i < arr_len; i++)
        {
            (*function)(arr[i]);
        }
        
    }

    template <typename T>
    void call(T &elem)
    {
        std::cout << "Call element: ";
        std::cout << elem << std::endl;
    }

#endif