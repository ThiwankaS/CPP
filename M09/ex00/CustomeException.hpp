#pragma once

#include <iostream>
#include <exception>

class CustomeException : public std::exception {

    protected:
        std::string message;

    public:
        CustomeException() noexcept;
        CustomeException(const std::string& msg) noexcept;
        CustomeException(const CustomeException& other) noexcept;
        CustomeException& operator=(const CustomeException& other) noexcept;
        ~CustomeException() noexcept;

        const char *what() const noexcept;
};
