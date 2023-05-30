#include "../include/MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}


template <typename T>
MutantStack<T>::MutantStack(const MutantStack& c) : std::stack<T>(c)
{
	*this = c;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &obj)
{
	*this = obj;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
	return std::stack<T>::c.rend();
}
