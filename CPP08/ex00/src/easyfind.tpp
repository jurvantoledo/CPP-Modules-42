#include "../include/easyfind.hpp"

const char* NoElementFound::what(void) const throw()
{
    return "No element found!";
}

template<typename T>
typename T::iterator easyfind(T container, int find)
{
    typename T::iterator ret = std::find(container.begin(), container.end(), find);
    if (ret == container.end())
    {
        throw NoElementFound();
    }
    return (ret);
}
