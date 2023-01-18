#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Created Zombie" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Bruh I dont even know what this is" << std::endl;
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}