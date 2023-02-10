#include "../include/Data.hpp"

Data::Data() : _value(0)
{
    std::cout << "Default constructor is called" << std::endl;
}

Data::Data(const Data &obj)
{
    std::cout << "Copy destructor is called" << std::endl;
    *this = obj;
}

Data& Data::operator=(const Data &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    this->_value = obj._value;
    return (*this);
}

Data::~Data()
{
    std::cout << "Destructor is called" << std::endl;
}

void Data::test()
{
    std::cout << "TEST" << std::endl;
    std::cout << "value is: " << this->_value << std::endl;
}