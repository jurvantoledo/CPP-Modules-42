#ifndef ARRAY_H

#define ARRAY_H
#include <iostream>
#include <cstdio>

template<typename T>
class Array
{
    private:
        T* _array;
        unsigned int _len;

        
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &obj);
        Array &operator=(const Array &obj);
        ~Array();

        T&		operator[] (size_t i) const;
        unsigned int  size() const;

        class IndexOutOfBoundsException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

template<typename T>
std::ostream& operator << (std::ostream &o, const Array<T> &a);

#include "../src/Array.tpp"

#endif