#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat Default Constructor is called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &obj)
{
    std::cout << "Cat Copy Constructor is called" << std::endl;
    *this = obj;
}

Cat& Cat::operator=(const Cat &obj)
{
    std::cout << "Copy Dog assignment operator called" << std::endl;
    this->type = obj.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor is called" << std::endl;
}


void Cat::makeSound() const
{
    std::cout << this->type << " Makes sad cat noises" << std::endl;
}