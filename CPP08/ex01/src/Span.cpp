#include "../include/Span.hpp"

Span::Span() {};

Span::Span(unsigned int n) : _max(n) {}

Span::Span(const Span &obj)
{
    *this = obj;
}

Span& Span::operator=(const Span &obj)
{
    this->_max = obj._max;
    this->_numbers = obj._numbers;
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int val)
{
    if (this->_numbers.size() <  _max)
        this->_numbers.push_back(val);
    else
        throw ArrayOverflow();
}

void    Span::fillSpan(int amount)
{
    for (int i = 0; i < amount; i++)
        addNumber(std::rand() % 100000);
}

int Span::shortestSpan()
{
    if (this->_numbers.size() <= 1)
        throw NotEnoughNumbers();

    std::vector<int> copy = this->_numbers;

    std::sort(copy.begin(), copy.end());
    int diff = longestSpan();
	for (unsigned long i = 0; i < copy.size() - 1; i++)
	{
		if (copy[i + 1] - copy[i] < diff)
			diff = copy[i + 1] - copy[i];
	}
    return (diff);
}

int Span::longestSpan()
{
    if (this->_numbers.size() <= 1)
        throw NotEnoughNumbers();

    std::vector<int> copy = this->_numbers;
    std::sort(copy.begin(), copy.end());
    return (copy.back());
}

const char* Span::ArrayOverflow::what(void) const throw() 
{
    return ("Overflow max size of array");
}

const char* Span::NotEnoughNumbers::what(void) const throw() 
{
    return ("Not enough numbers");
}