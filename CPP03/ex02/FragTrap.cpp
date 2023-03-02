#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default constructor is called" << std::endl;
    this->name = "Eman";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Default constructor is called" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " created!" <<std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    std::cout << "Copy constructor is called" << std::endl;
    this->name = obj.name;
    this->hitPoints = obj.hitPoints;
    this->energyPoints = obj.energyPoints;
    this->attackDamage= obj.attackDamage;
}


void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap High fives" << std::endl;
}