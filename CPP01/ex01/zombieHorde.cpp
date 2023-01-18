#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    // Maken een array van zombies;
    Zombie *horde = new Zombie[N];

    // loopen over N zombies heen en geven de naam Bert mee en announcen de zombie met naam Bert
    int i = 0;
    while (i < N)
    {
        horde[i].nameZombie("Bert");
        horde[i].announce();
        i++;
    }

    // returnen de horde
    return horde;
}