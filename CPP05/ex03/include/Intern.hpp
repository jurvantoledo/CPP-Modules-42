#ifndef INTERN_H

#define INTERN_H
#include <iostream>

class Intern
{
    private:
        /* data */
    
    public:
        Intern();
        Intern(const Intern &obj);
        Intern &operator=(const Intern &obj);
        ~Intern();
};

#endif