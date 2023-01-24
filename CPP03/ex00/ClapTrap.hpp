#ifndef CLAPTRAP_H

#define CLAPTRAP_H
#include <iostream>

class ClapTrap
{
    public:
        ClapTrap(std::string name);
        ~ClapTrap();

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
};

#endif