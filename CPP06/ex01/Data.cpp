#include "./include/Data.hpp"

Data::Data()
{
    std::cout << "Default constructor is called" << std::endl;
}

Data::Data(const Data &obj)
{
    std::cout << "Copy destructor is called" << std::endl;
}

Data& Data::operator=(const Data &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
}

Data::~Data()
{
    std::cout << "Destructor is called" << std::endl;
}