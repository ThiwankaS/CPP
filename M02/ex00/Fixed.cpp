#include "Fixed.hpp"

const int Fixed::fp_bits = 8;

Fixed::Fixed() : fp_vlaue(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called\n";
    if(this != &other) {
        this->fp_vlaue = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return (fp_vlaue);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    fp_vlaue = raw;
}
