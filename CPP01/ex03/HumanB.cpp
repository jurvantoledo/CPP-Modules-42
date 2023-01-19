#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
    return ;
}

HumanB::~HumanB()
{
    return ;
}

void HumanB::attack()
{
    if (!this->_weapon)
    {
        std::cout << this->_name << " Is going to fist you" << std::endl;
        return ;
    }
    std::cout << this->_name << " Attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

