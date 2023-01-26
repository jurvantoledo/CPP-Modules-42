#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Default Dog Constructor is called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
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
    this->brain = obj.brain;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor is called" << std::endl;
    delete this->brain;
}


void Dog::makeSound() const
{
    std::cout << this->type << " Makes sad dog noises" << std::endl;
}