#ifndef WRONG_ANIMAL_H

#define WRONG_ANIMAL_H
#include "Animal.hpp"

class WrongAnimal: public Animal
{
    public:
        WrongAnimal(/* args */);
        WrongAnimal(const WrongAnimal &obj);
        WrongAnimal &operator=(const WrongAnimal &obj);
        ~WrongAnimal();
    private:
        /* data */
};

#endif