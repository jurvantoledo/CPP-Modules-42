#ifndef MUTANTSTACK_H

#define MUTANTSTACK_H
#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
    private:
        
    public:
        MutantStack();
        MutantStack(const MutantStack &obj);
        ~MutantStack();

        MutantStack& operator=(const MutantStack &obj);

        typedef typename std::stack<T>::container_type::iterator iter;
        typedef typename std::stack<T>::container_type::const_iterator const_iter;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iter;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iter;

        iter                begin();
        iter                end();
        // const_iter          begin() const;
        // const_iter          end() const;
        reverse_iter        rbegin();
        reverse_iter        rend();
        // const_reverse_iter  rbegin() const;
        // const_reverse_iter  rend() const;
};

#include "../src/MutantStack.tpp"

#endif