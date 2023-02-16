#include "../include/Span.hpp"

Span::Span(size_t amount) : max(amount)
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
    (void)obj;
    return (*this);
}

Span::~Span()
{
    std::cout << "Destructor is called" << std::endl;
}

void Span::addNumber(int val)
{
    this->_numbers.insert(val);
}