#ifndef FIXED_H

#define FIXED_H
#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(int const val);
        Fixed(float const val);
        Fixed(Fixed const &p1);
        ~Fixed();

        Fixed &operator=(const Fixed &p1);

        // Comparison operators
        bool operator>(const Fixed &comp);
        bool operator<(const Fixed &comp);
        bool operator>=(const Fixed &comp);
        bool operator<=(const Fixed &comp);
        bool operator==(const Fixed &comp);
        bool operator!=(const Fixed &comp);

        // Artithmetic operators
        Fixed operator+ (const Fixed &fixed) const;
        Fixed operator- (const Fixed &fixed) const;
        Fixed operator* (const Fixed &fixed) const;
        Fixed operator/ (const Fixed &fixed) const;

        // Increment / Decrement operators
        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        // Member functions
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        // Static member functions
        Fixed &min(Fixed &a, Fixed &b);
        Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

    private:
        int value;
        static const int fractionalBits = 8;
};

    // Output stream operator
    std::ostream& operator<<(std::ostream &o, const Fixed &fixed);

#endif