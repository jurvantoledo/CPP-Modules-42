#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "Default Constructor is called" << std::endl;
    this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat &obj)
{
    std::cout << "Copy Constructor is called" << std::endl;
    *this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
    std::cout << "Copy Assignment operator is called" << std::endl;
    this->type = obj.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor is called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << this->type << " Makes WrongCat noises" << std::endl;
}