#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default Constructor is called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &obj) 
{
    std::cout << "Animal Copy Constructor is called" << std::endl;
    *this = obj;
}

Animal& Animal::operator=(const Animal &obj)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    this->type = obj.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor is called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << this->type << " Makes sound" << std::endl;
}

std::string Animal::getType(void) const
{
    return this->type;
}