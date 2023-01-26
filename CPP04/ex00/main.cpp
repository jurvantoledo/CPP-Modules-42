#include "Animal.hpp"

int main()
{
    const Animal* j = new Dog();

    std::cout << j->getType() << " " << std::endl;
    return (0);
}