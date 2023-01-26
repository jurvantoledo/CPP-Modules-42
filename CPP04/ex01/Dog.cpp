#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Default Dog Constructor is called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Copy Dog Constructor is called" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << "Copy Dog assignment operator called" << std::endl;
    this->type = obj.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor is called" << std::endl;
}


void Dog::makeSound() const
{
    std::cout << this->type << " Makes sad dog noises" << std::endl;
}