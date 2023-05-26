#ifndef ITER_H

#define ITER_H
#include <iostream>
#include <array> 

    template <typename T>
    void iter(T* arr, size_t arr_len, void (*function)(T&))
    {
        if (!arr)
            return ;
        for (size_t i = 0; i < arr_len; i++)
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