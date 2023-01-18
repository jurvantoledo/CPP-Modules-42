#ifndef ZOMBIE_H

#define ZOMBIE_H
#include <iostream>

class Zombie
{
    public:
        Zombie();
        ~Zombie();

        void announce();
        void nameZombie(std::string name);

    private:
        std::string name;
};

#endif