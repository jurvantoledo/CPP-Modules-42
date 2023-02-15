#include "../include/easyfind.hpp"
#include <vector>
#include <iterator>

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