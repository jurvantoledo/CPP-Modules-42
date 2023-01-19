#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
    this->_type = weapon;
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