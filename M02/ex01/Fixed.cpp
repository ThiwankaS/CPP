#include "Fixed.hpp"

const int Fixed::fp_bits = 8;

Fixed::Fixed() : fp_vlaue(0) {
    std::cout << "Default constructor called. \n";
}

Fixed::Fixed(const int input) {
    std::cout << "Int constructor called. \n";
    this->fp_vlaue = input << this->fp_bits;
}

Fixed::Fixed(const float input) {
    std::cout << "Float constructor called. \n";
    this->fp_vlaue = roundf(input * ( 1 << this->fp_bits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called. \n";
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called. \n";
    if(this != &other) {
        this->fp_vlaue = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called. \n";
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called. \n";
    return (fp_vlaue);
}

void Fixed::setRawBits(int const raw) {
    //std::cout << "setRawBits member function called. \n";
    fp_vlaue = raw;
}

int Fixed::toInt(void) const {
    return (this->fp_vlaue >> this->fp_bits);
}

float Fixed::toFloat(void) const {
    return ((float)this->fp_vlaue / (float)(1 << this->fp_bits));
}

/**
 * operator oveloading for "<<" to display Fixed class instance's values
 * using standard cout statments
*/

std::ostream &operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}
