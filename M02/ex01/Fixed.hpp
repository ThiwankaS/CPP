#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

    private:
        int fp_vlaue;
        static const int fp_bits;

    public:
        // default constructor
        Fixed();
        // Int constructor
        Fixed(const int input);
        // Float constructor
        Fixed(const float input);
        // copy constructor
        Fixed(const Fixed& other);
        // assignment constructor
        Fixed& operator=(const Fixed& other);
        // default destructor
        ~Fixed();

        // class methods
        int getRawBits(void) const ;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

// << operator overloading
std::ostream &operator<<(std::ostream& os, const Fixed& fixed);

#endif
