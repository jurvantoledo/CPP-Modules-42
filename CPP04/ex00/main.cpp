#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animal1 = new Dog();
    const Animal* animal2 = new Cat();
    const WrongAnimal* wrongAnimal1 = new WrongCat();
    const WrongAnimal* wrongAnimal2 = new WrongAnimal();

    {
        std::cout << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "A DAWG" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << animal1->getType() << " " << std::endl;
        animal1->makeSound();
        delete animal1;
        std::cout << "---------------------------------" << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "A Cat" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << animal2->getType() << " " << std::endl;
        animal2->makeSound();
        delete animal2;
        std::cout << "---------------------------------" << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Not a wrong Cat" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << wrongAnimal1->getType() << " " << std::endl;
        wrongAnimal1->makeSound();
        delete wrongAnimal1;
        std::cout << "---------------------------------" << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "A wrong Animal" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << wrongAnimal2->getType() << " " << std::endl;
        wrongAnimal2->makeSound();
        delete wrongAnimal2;
        std::cout << "---------------------------------" << std::endl;
        std::cout << std::endl;
    }
    return (0);
}