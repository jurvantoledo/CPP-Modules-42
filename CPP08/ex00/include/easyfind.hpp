#ifndef EASYFIND_H

#define EASYFIND_H
#include <exception>
#include <iterator>

class NoElementFound: public std::exception
{
    public:
        const char *what() const throw()
        {
            return ("Element not found");
        }
};

template<typename T>
typename T::iterator easyfind(T container, int find);

#include "../src/easyfind.tpp"

#endif