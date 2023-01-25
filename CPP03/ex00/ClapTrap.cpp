#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor is called" << std::endl;
    this->name = "gangster";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Default Constructor is called" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap " << this->name << " created!" <<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &old)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = old;
    this->hitPoints = old.hitPoints;
    this->energyPoints = old.energyPoints;
    this-> attackDamage = old.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &old)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->name = old.name;
    return (*this);
}

void ClapTrap::attack(const std::string &target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
    }
    else
    {
        if (this->energyPoints > 0)
        {
            std::cout << "ClapTrap " << this->name << " attacks " << target << " causing "; 
            std::cout << this->attackDamage << " damage" << std::endl;
            this->energyPoints--;
        }
        else
            std::cout << "No Energy Left" << std::endl;
        std::cout << "Total Energy "<<  this->energyPoints << std::endl << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " Takes " << amount << " Damage" << std::endl;
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " has " << this->hitPoints; 
        std::cout << " Hitpoints left after attack" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap is already dead" << std::endl;
        return ;
    }
    else
    {
        if (this->energyPoints > 0)
        {
            std::cout << "ClapTrap " << this->name << " repairs " << amount << " hit points" << std::endl;
            this->hitPoints = hitPoints + amount;
            std::cout << "Total hitpoints after repair " << this->hitPoints << std::endl;
            this->energyPoints--;
        }
        else
            std::cout << "No Eneregy Left" << std::endl;
        std::cout << "Total Energy "<<  this->energyPoints << std::endl << std::endl;
    }
}