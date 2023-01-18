#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Created Zombie" << std::endl;
}

// Destructors:
/*
    - Destructor is also a special member function like constructor. 
      Destructor destroys the class objects created by constructor.
    - Destructor has the same name as their class name preceded by a tilde (~) symbol.
    - It is not possible to define more than one destructor.
    - The destructor is only one way to destroy the object create by constructor. Hence destructor can-not be overloaded.
    - Destructor neither requires any argument nor returns any value.
    - It is automatically called when object goes out of scope.
    - Destructor release memory space occupied by the objects created by constructor.
    - In destructor, objects are destroyed in the reverse of an object creation.
*/
Zombie::~Zombie()
{
    std::cout << "Zombie is deleted " << this->name << std::endl;
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}