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

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

    private:
        int storeFixedPoint;
        static const int fractionalBits = 8;
};

    std::ostream& operator<<(std::ostream &o, const Fixed &fixed);

#endif