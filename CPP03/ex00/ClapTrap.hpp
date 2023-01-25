#ifndef CLAPTRAP_H

#define CLAPTRAP_H
#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &old);
        ClapTrap &operator=(const ClapTrap &old);
        ~ClapTrap();

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
};

#endif