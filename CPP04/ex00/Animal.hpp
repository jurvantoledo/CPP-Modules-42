#ifndef ANIMAL_H

#define ANIMAL_H
#include <iostream>

class Animal
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