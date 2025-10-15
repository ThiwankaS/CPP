#pragma once

#include <iostream>
#include <exception>
#include <string>

class CustomeException : public std::exception {

    private:
        std::string msg;

    public:
        CustomeException(const std::string& str) noexcept;
        CustomeException(const CustomeException& other) noexcept;
        CustomeException& operator=(const CustomeException& other) noexcept;
        ~CustomeException() noexcept;

        const char *what() const noexcept;
};
