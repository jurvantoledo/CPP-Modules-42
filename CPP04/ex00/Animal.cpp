#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default Constructor is called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Destructor is called" << std::endl;
}

Animal::Animal(const Animal &obj) 
{
    std::cout << "Copy Constructor is called" << std::endl;
}

Animal& Animal::operator=(const Animal &old)
{
    std::cout << "Copy assignment operator called" << std::endl;
}