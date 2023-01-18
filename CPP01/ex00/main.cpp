#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie *zombie;

    std::cout << "Created zombie with newZombie function" << std::endl;
    zombie = newZombie("dikzak");

    std::cout << "Deleted zombie" << std::endl;
    delete zombie;

    std::cout << "Created zombie with randomChump function" << std::endl;
    randomChump("Dikzak random");
    return (0);
}