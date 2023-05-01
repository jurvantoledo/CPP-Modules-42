#include "../include/easyfind.hpp"
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> test;
    std::vector<int>::iterator find;

    test.push_back(2);
    test.push_back(4);
    test.push_back(44);
    test.push_back(1677);

    try
    {
        std::cout << *easyfind(test, 4) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}