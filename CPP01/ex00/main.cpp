#include "Zombie.hpp"

// Stack vs Heap
/* 
    Gebruik de Stack wanneer je variabele niet zal worden gebruikt nadat de huidige functie returned. 
    Gebruik de Heap wanneer de gegevens in de variabele nodig zijn na de levensduur van de huidige functie.
*/

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie *zombie;

    std::cout << "Created zombie with newZombie function" << std::endl;
    zombie = newZombie("Jan");
    // Delete zombie om memory leaks te vermijden. Op deze manier ga je ook door je destructor
    std::cout << "Deleted zombie" << std::endl;
    delete zombie;

    // Zombie aangemaakt op de stack gaat automatisch door destructor
    std::cout << "Created zombie with randomChump function" << std::endl;
    randomChump("Bert");
    return (0);
}