#ifndef GRADEEXCEPTION_HPP
#define GRADEEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

class GradeException : public std::exception {

    public:
        enum Type { TooHigh, TooLow, Unknown };
        GradeException() noexcept;
        GradeException(Type _type) noexcept;
        GradeException(const GradeException& other) noexcept;
        GradeException& operator=(const GradeException& other) noexcept;
        virtual ~GradeException();
        virtual const char *what() const noexcept override;
    
    protected:
        Type type;
};

#endif
