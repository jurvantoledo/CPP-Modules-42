#ifndef MUTANTSTACK_H

#define MUTANTSTACK_H
#include <iostream>
#include <exception>

class MutantStack
{
    private:
        
    public:
        MutantStack();
        MutantStack(size_t n);
        ~MutantStack();

        MutantStack(const MutantStack &obj);
        MutantStack& operator=(const MutantStack &obj);
};


#endif