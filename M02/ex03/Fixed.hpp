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

        // comparisson operators
        bool operator>(Fixed fixed) const;
        bool operator>=(Fixed fixed) const;
        bool operator<(Fixed fixed) const;
        bool operator<=(Fixed fixed) const;
        bool operator==(Fixed fixed) const;
        bool operator!=(Fixed fixed) const;

        // arithmatic operators
        float operator+(Fixed fixed) const;
        float operator-(Fixed fixed) const;
        float operator*(Fixed fixed) const;
        float operator/(Fixed fixed) const;

        // increment operators
        Fixed operator++();
        Fixed operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        // min functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);

        // max functions
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        // class methods
        int getRawBits(void) const ;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

// << operator overloading
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
