#include "Zombie.hpp"

// Constructor voor Zombie class
Zombie::Zombie()
{
    std::cout << "Constructor activated" << std::endl;
}

// destructor voor Zombie class
Zombie::~Zombie()
{
    std::cout << "Destructor activated" << std::endl;
}

// Functie die de naam van de zombie aan de class mee geeft
void Zombie::nameZombie(std::string name)
{
    this->name = name;
}

// Functie die de zombie announced
void Zombie::announce()
{
    std::cout << name << ": Brainz..." << std::endl;
}