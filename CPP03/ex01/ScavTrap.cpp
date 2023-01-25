#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Default constructor is called" << std::endl;
    this->name = "Bruh";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Default constructor is called" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ClapTrap &old) : ClapTrap()
{
    std::cout << "Copy constructor is called" << std::endl;
    this->name = old.name;
    this->hitPoints = old.hitPoints;
    this->energyPoints = old.energyPoints;
    this->attackDamage = old.attackDamage;
}