#ifndef FRAGTRAP_H

#define FRAGTRAP_H
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const ClapTrap &obj);
        ~FragTrap();

        void highFivesGuys(void);

    private:
        /* data */
};

#endif