#ifndef ANIMAL_H

#define ANIMAL_H
#include <iostream>

/**
* @brief
* So we made the class abstract which means its no longer instantiable. but it 
* can be used as a base class.
* = 0 is known as pure-specifier, and appears either immediately after 
* the declarator or after the optional virt-specifier.
* 
* @brief A class is abstract if it has at least one pure virtual member function.
*/
class Animal
{
    public:
        Animal();
        Animal(const Animal &obj);
        Animal &operator = (const Animal &obj);
        virtual ~Animal() = 0;

        /**
         * @brief
         * Basically, a virtual function is used in the base class in order to ensure that the function is overridden. 
         * This especially applies to cases where a pointer of base class points to an object of a derived class.
         * 
         */
        virtual void makeSound(void) const = 0;
        std::string getType(void) const;
    
    protected:
        std::string type;

    private:
};

#endif