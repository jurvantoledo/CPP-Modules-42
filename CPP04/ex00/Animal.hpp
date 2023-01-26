#ifndef ANIMAL_H

#define ANIMAL_H
#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const Animal &obj);
        Animal &operator = (const Animal &obj);
        virtual ~Animal();

        /**
         * @brief 
         * Basically, a virtual function is used in the base class in order to ensure that the function is overridden. 
         * This especially applies to cases where a pointer of base class points to an object of a derived class.
         * 
         */
        virtual void makeSound(void) const;
        std::string getType(void) const;
    
    protected:
        std::string type;

    private:
};

#endif