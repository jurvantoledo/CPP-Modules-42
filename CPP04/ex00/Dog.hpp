#ifndef DOG_H

#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &old_obj);
		Dog &operator=(const Dog &old_obj);
        ~Dog();

        void makeSound() const;

    private:
};

#endif