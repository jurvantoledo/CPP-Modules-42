#include "../include/Span.hpp"

Span::Span(size_t amount) : _max(amount)
{
    std::cout << "Default constructor is called" << std::endl;
}

Span::Span(const Span &obj)
{
    std::cout << "Copy constructor is called" << std::endl;
    *this = obj;
}

Span& Span::operator=(const Span &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    this->_max = obj._max;
    this->_numbers = obj._numbers;
    return (*this);
}

Span::~Span()
{
    std::cout << "Destructor is called" << std::endl;
}

void Span::addNumber(int val)
{
    if (this->_numbers.size() <  _max)
        this->_numbers.push_back(val);
    else
        throw ArrayOverflow();
}

int Span::shortestSpan()
{
    if (this->_numbers.size() < 2)
    {
        throw NotEnoughNumbers();
    }
    
    std::vector<int> copy = this->_numbers;

    std::sort(copy.begin(), copy.end());

    return (copy.front());
}

int Span::longestSpan()
{
    if (this->_numbers.size() < 2)
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