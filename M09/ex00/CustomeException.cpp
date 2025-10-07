#include "CustomeException.hpp"

CustomeException::CustomeException() noexcept
: message("unknown"){}

CustomeException::CustomeException(const std::string& msg) noexcept
: message(msg){}

CustomeException::CustomeException(const CustomeException& other) noexcept
: message(other.message){}

CustomeException& CustomeException::operator=(const CustomeException& other) noexcept {
    if(this != &other) {
        this->message = other.message;
    }
    return (*this);
}

CustomeException::~CustomeException() noexcept {}

const char* CustomeException::what() const noexcept {
    return this->message.c_str();
}
