#ifndef ARRAY_H

#define ARRAY_H
#include <iostream>
#include <exception>
#include <cstdio>

template<typename T>
class Array
{
    private:
        T *_array;
        int _len;

        class IndexOutOfBoundsException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Accessed index out of Array bounds");
                }
        };
        
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &obj);
        Array &operator=(const Array &obj);
        ~Array();

        T&		operator[] (size_t i) const;
        size_t  size();

};

template<typename T>
std::ostream& operator << (std::ostream &o, const Array<T> &a);

#include "../src/Array.tpp"

#endif