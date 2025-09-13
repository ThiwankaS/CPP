#ifndef CUSTOMEEXCEPTION_HPP
#define CUSTOMEEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

enum Type { TooHigh, TooLow, NotSigned, Unknown };
class CustomeException : public std::exception {

    protected:
        Type type;

    public:
        //constructors & destructor
        CustomeException() noexcept;
        CustomeException(Type _type) noexcept;
        CustomeException(const CustomeException& other) noexcept;
        CustomeException& operator=(const CustomeException& other) noexcept;
        virtual ~CustomeException();
        //class methods
        virtual const char *what() const noexcept override;
};

#endif
