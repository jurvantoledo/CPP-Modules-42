#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->storeFixedPoint = 0;
    return ;
}

Fixed::Fixed(int const val)
{
    std::cout << "Int constructor called" << std::endl;
    this->storeFixedPoint = (val << fractionalBits);
}

Fixed::Fixed(float const val)
{
    std::cout << "Float constructor called" << std::endl;
    this->storeFixedPoint = int(roundf(val * (1 << fractionalBits)));
}

Fixed::Fixed(Fixed const &p1)
{
	std::cout << "Copy constructor called" << std::endl;
	this->storeFixedPoint = p1.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
    return ;
}

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

float Fixed::toFloat(void) const 
{
    return float(this->storeFixedPoint) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->storeFixedPoint >> fractionalBits;
}

/**
 * @brief std::ostream
 * The ostream class has methods for formatting output.
 * These output stream objects are used to write data as a sequence of characters on the screen.
 */

/**
 * @brief Overload Operators
 * Overloaded operators are functions with special names: 
 * the keyword "operator" followed by the symbol for the operator being defined. 
 * Like any other function, an overloaded operator has a return type and a parameter list.
 */
std::ostream& operator<<(std::ostream &o, const Fixed &fixed)
{
    o << fixed.toFloat();
    return o;
}