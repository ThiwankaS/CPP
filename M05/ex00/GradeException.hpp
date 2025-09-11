#ifndef GRADEEXCEPTION_HPP
#define GRADEEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

class GradeException : public std::exception {

    protected:
        enum Type { TooHigh, TooLow, Unknown };
        Type type;

    public:
        GradeException() noexcept;
        GradeException(Type _type) noexcept;
        GradeException(const GradeException& other) noexcept;
        GradeException& operator=(const GradeException& other) noexcept;
        virtual ~GradeException();
        virtual const char *what() const noexcept override;
};

#endif
