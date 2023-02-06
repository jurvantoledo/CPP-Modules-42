#include "../include/Types.hpp"

Types::Types()
{
    std::cout << "Default constructor is called" << std::endl;
}

Types::Types(const Types &obj)
{
    std::cout << "Copy constructor is called" << std::endl;
}

Types& Types::operator=(const Types &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
}

Types::~Types()
{
    std::cout << "Destructor is called" << std::endl;
}