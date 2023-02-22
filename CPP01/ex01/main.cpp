#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
    Zombie *horde;

    horde = zombieHorde(5, "Bert");

    delete[] horde;
    return 0;
}