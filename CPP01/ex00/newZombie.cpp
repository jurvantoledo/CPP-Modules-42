#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    // Wanneer je new gebruikt maak je een nieuwe zombie aan op de heap
    Zombie *newZombie = new Zombie(name);
    newZombie->announce();
    return (newZombie);
}