#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->storeFixedPoint = 0;
    return ;
}

Fixed::Fixed(const Fixed &p1)
{
    std::cout << "Copy constructor called" << std::endl;
    this->storeFixedPoint = p1.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}

/**
 * @brief 
 * The Copy constructor and the assignment operators are used to initializing one object to another object.
 * The main difference between them is that the copy constructor creates a separate memory block for the new object.
 * But the assignment operator does not make new memory space.
 */

Fixed &Fixed::operator=(const Fixed &p1)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->storeFixedPoint = p1.getRawBits();
    return *this;
}

int Fixed::getRawBits() const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->storeFixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->storeFixedPoint = raw;
}