#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {

    private:
        int fp_vlaue;
        static const int fp_bits;

    public:
        // default constructor
        Fixed();
        // copy constructor
        Fixed(const Fixed& other);
        // assignment constructor
        Fixed& operator=(const Fixed& other);
        // default destructor
        ~Fixed();

        // class methods
        int getRawBits(void) const ;
        void setRawBits(int const raw);
};

#endif
