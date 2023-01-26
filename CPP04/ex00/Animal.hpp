#ifndef ANIMAL_H

#define ANIMAL_H
#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

class Animal
{
    public:
        Animal();
        Animal(const Animal &obj);
        Animal &operator = (const Animal &obj);
        virtual ~Animal();

        virtual void makeSound(void) const;
        std::string getType(void) const;
    
    protected:
        std::string type;

    private:
};

#endif