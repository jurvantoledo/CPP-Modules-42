#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain &obj);
        Brain &operator = (const Brain &obj);
        ~Brain();

        std::string ideas[100];
    private:
};

#endif