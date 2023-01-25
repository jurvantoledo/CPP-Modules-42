#ifndef CAT_H

#define CAT_H
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat();
        ~Cat();

        void makeSound();
    private:
        /* data */
};

#endif