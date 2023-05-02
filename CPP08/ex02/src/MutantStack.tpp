#include "../include/MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "Constructor is called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Destructor is called" << std::endl;
}
