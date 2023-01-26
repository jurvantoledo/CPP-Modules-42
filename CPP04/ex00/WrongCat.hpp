#ifndef WRONG_CAT_H

#define WRONG_CAT_H
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &obj);
        WrongCat &operator=(const WrongCat &obj);
        ~WrongCat();

    private:
        /* data */
};

#endif