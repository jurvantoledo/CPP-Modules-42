#include "../include/Types.hpp"

Types::Types(const std::string &value) : _value(value)
{
    std::cout << "Default constructor is called" << std::endl;
}

Types::Types(const Types &obj)
{
    std::cout << "Copy constructor is called" << std::endl;
    *this = obj;
}

Types& Types::operator=(const Types &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    (void)obj;
    return (*this);
}

Types::~Types()
{
    std::cout << "Destructor is called" << std::endl;
}

void Types::getTypes()
{
    if (this->_value.length() == 1)
    {   

    }
    std::cout << this->_value << std::endl;
}

void Types::ToChar()
{

}
