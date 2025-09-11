#include "GradeException.hpp"

GradeException::GradeException() noexcept
: type(Unknown) {}

GradeException::GradeException(Type _type) noexcept
: type(_type) {}

GradeException::GradeException(const GradeException& other) noexcept
: type(other.type) {}

GradeException& GradeException::operator=(const GradeException& other) {
    if(this != &other) {
        *this = other;
    }
    return (*this);
}

const char* GradeException::GradeException::what() const throw() {
    return (
        type == TooHigh
            ? "Grade too high"
            : "Grade too low"
    );
}

GradeException::~GradeException () {}
