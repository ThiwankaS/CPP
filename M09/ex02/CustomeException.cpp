#include "CustomeException.hpp"

CustomeException::CustomeException(const std::string& str) noexcept:
msg(str) {}

CustomeException::CustomeException(const CustomeException& other) noexcept:
msg(other.msg) {}

CustomeException& CustomeException::operator=(const CustomeException& other) noexcept {
    if (this != &other) {
        this->msg = other.msg;
    }
    return (*this);
}

CustomeException::~CustomeException() noexcept {}

const char* CustomeException::what() const noexcept {
    return (msg.c_str());
}
