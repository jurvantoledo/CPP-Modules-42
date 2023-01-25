#ifndef ANIMAL_H

#define ANIMAL_H
#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

class Animal: public Cat, public Dog
{
    public:
        Animal();
        Animal(const Animal &obj);
        ~Animal();

    private:
    
    protected:
        std::string type;
};

#endif