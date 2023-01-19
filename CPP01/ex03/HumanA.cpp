#include "HumanA.hpp"

// initializing in function
HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name)
{
    return ;
}

HumanA::~HumanA()
{
    return ;
}

void HumanA::attack()
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}