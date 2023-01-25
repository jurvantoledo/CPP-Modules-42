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

ScavTrap::ScavTrap(const ClapTrap &old) : ClapTrap(old)
{
    std::cout << "Copy constructor is called" << std::endl;
    this->name = old.name;
    this->hitPoints = old.hitPoints;
    this->energyPoints = old.energyPoints;
    this->attackDamage = old.attackDamage;
}

void ScavTrap::attack(const std::string &target)
{
    if (hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " is already dead" << std::endl;
    }
    else
    {
       if (this->energyPoints > 0)
       {
            std::cout << "ScavTrap " << this->name << " attacks " << target << " causing "; 
            std::cout << this->attackDamage << " damage" << std::endl;
            this->energyPoints--;
       }
        else
            std::cout << "No Energy Left" << std::endl;
        std::cout << "Total Energy "<<  this->energyPoints << std::endl << std::endl;
    }
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->name << " is in gate keeper mode" << std::endl;
}