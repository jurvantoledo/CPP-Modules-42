#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Default Constructor is called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "Copy Constructor is called" << std::endl;
    *this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
    std::cout << "Copy Assignment operator is called" << std::endl;
    this->type = obj.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor is called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << this->type << " Makes wrong noises" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}