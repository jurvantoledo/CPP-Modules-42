#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal *AnimalArray[10];

    // 5 Dogs in array
    for (int i = 0; i < 5; i++)
    {
        AnimalArray[i] = new Dog();
    }

    // 5 Cats in array
    for (int i = 5; i < 10; i++)
    {
        AnimalArray[i] = new Cat();
    }
    
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Dog and cat noises" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    AnimalArray[1]->makeSound();
    AnimalArray[9]->makeSound();

    std::cout << "---------------------------------------------" << std::endl;

    // delete full array
    for (int i = 0; i < 10; i++)
    {
       delete AnimalArray[i];
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;


    // Onderstaande code is dus niet meer mogelijk omdat door virtual = 0 de class abstract is geworden
    // const Animal* meta = new Animal();
    
    return (0);
}