#include "Zombie.hpp"

void randomChump(std::string name)
{
    // Zo maak je nieuwe zombie aan op de stack
    Zombie zombie(name);
    zombie.announce();
}