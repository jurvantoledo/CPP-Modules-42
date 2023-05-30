#include "../include/easyfind.hpp"
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> test;

    test.push_back(2);
    test.push_back(4);
    test.push_back(44);
    test.push_back(1677);

    std::cout << std::endl;
    std::cout << "------------------------ TEST SHOULD SUCCEED --------------------" << std::endl;
    try
    {
        std::cout << *easyfind(test, 1677) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << "------------------------ TEST SHOULD FAIL -----------------------" << std::endl;
    try
    {
        std::cout << *easyfind(test, 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    return (0);
}