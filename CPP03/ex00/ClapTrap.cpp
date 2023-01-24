#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Constructor is called" << std::endl;
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor is called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " Takes " << amount << " Damage" << std::endl;
    this->_hitPoints -= amount;
    this->_energyPoints -= 1;
    std::cout << "ClapTrap has " << this->_hitPoints << " hit points left after attack" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hitPoints += amount;
    this->_energyPoints -= amount;
}