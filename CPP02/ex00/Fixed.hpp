#ifndef FIXED_H

#define FIXED_H
#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& p1);
        ~Fixed();
        Fixed &operator=(const Fixed &p1);

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int storeFixedPoint;
        static const int fractionalBits = 8;
};

#endif