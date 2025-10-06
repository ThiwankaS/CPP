#include "CustomeException.hpp"

CustomeException::CustomeException()
: message("unknown"){}

CustomeException::CustomeException(const std::string& msg)
: message(msg){}

CustomeException::CustomeException(const CustomeException& other)
: message(other.message){}

CustomeException& CustomeException::operator=(const CustomeException& other) {
    if(this != &other) {
        this->message = other.message;
    }
    return (*this);
}

CustomeException::~CustomeException() {}

const char* CustomeException::what() const noexcept {
    std::cerr << this->message;
}
