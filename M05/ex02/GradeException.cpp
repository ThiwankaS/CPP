#include "GradeException.hpp"

GradeException::GradeException() noexcept
: type(Unknown) {
    std::cout << "GradeException default constructor.\n";
}

GradeException::GradeException(Type _type) noexcept
: type(_type) {
    std::cout << "GradeException argument constructor.\n";
}

GradeException::GradeException(const GradeException& other) noexcept
: type(other.type) {
    std::cout << "GradeException copy constructor.\n";
}

GradeException& GradeException::operator=(const GradeException& other) noexcept {
    if(this != &other) {
        *this = other;
    }
    std::cout << "GradeException assigment operator.\n";
    return (*this);
}

const char* GradeException::GradeException::what() const throw() {
    return (
        type == TooHigh
            ? "Grade too high"
            : "Grade too low "
    );
}

GradeException::~GradeException () {
    std::cout << "GradeException destructor.\n";
}
