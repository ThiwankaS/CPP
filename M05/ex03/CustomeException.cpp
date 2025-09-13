#include "CustomeException.hpp"

CustomeException::CustomeException() noexcept
: type(Unknown) {
    std::cout << "CustomeException default constructor.\n";
}

CustomeException::CustomeException(Type _type) noexcept
: type(_type) {
    std::cout << "CustomeException argument constructor.\n";
}

CustomeException::CustomeException(const CustomeException& other) noexcept
: type(other.type) {
    std::cout << "CustomeException copy constructor.\n";
}

CustomeException& CustomeException::operator=(const CustomeException& other) noexcept {
    if(this != &other) {
        *this = other;
    }
    std::cout << "CustomeException assigment operator.\n";
    return (*this);
}

const char* CustomeException::CustomeException::what() const throw() {
    return (
        "Unknown execption has occured"
    );
}

CustomeException::~CustomeException () {
    std::cout << "CustomeException destructor.\n";
}
