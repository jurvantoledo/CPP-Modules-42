#ifndef WRONG_ANIMAL_H

#define WRONG_ANIMAL_H
#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(/* args */);
        WrongAnimal(const WrongAnimal &obj);
        WrongAnimal &operator=(const WrongAnimal &obj);
        virtual ~WrongAnimal() = 0;

        virtual void makeSound() const = 0;
        std::string getType(void) const;
    
    protected:
        std::string type;

    private:
};

#endif