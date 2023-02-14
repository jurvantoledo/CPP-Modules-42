#ifndef WHATEVER_H

#define WHATEVER_H
#include <iostream>

    template <typename T>
    T swap(T val1, T val2)
    {
        // T temp;

        val1 = val2;
        // val2 = temp;
        // temp = val1;
        return 0;
    };

    template <typename S>
    S min(S val1, S val2)
    {
        if (val1 < val2)
        {
            std::cout << "The first value is called: " << val1 << std::endl;
            return val1;
        }
        std::cout << "The second value is called: " << val2 << std::endl;
        return val2;
    }

    template <typename M>
    M max(M val1, M val2)
    {
        if (val1 > val2)
        {
            std::cout << "The first value is called: " << val1 << std::endl;
            return val1;
        }
        std::cout << "The second value is called: " << val2 << std::endl;
        return val2;
    }


#endif