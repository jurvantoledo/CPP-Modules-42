#ifndef WRONG_ANIMAL_H

#define WRONG_ANIMAL_H
#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(/* args */);
        WrongAnimal(const WrongAnimal &obj);
        WrongAnimal &operator=(const WrongAnimal &obj);
        virtual ~WrongAnimal();

        virtual void makeSound() const;
        std::string getType(void) const;
    
    protected:
        std::string type;

    private:
};

#endif