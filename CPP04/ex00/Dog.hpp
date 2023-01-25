#ifndef DOG_H

#define DOG_H
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog();
        ~Dog();

        void makeSound();
    private:
        /* data */
};

#endif