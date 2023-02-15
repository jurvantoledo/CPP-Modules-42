#include "../include/Span.hpp"

Span::Span(size_t amount) : max(amount)
{
    std::cout << "Default constructor is called" << std::endl;
}

Span::~Span()
{
    std::cout << "Destructor is called" << std::endl;
}