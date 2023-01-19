#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
    this->_type = weapon;
    std::cout << "Weapon is: " << _type << std::endl;
    return;
}

Weapon::~Weapon()
{
    return;
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

std::string const &Weapon::getType()
{
    std::string const &typeRef = _type;
    return typeRef;
}