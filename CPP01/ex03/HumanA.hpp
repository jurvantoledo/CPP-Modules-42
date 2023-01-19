#ifndef HUMAN_A_H

#define HUMAN_A_H
#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();

    void attack(void);

private:
    std::string _name;
    Weapon &_weapon;
};

#endif