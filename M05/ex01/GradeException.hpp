#ifndef GRADEEXCEPTION_HPP
#define GRADEEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

enum Type { TooHigh, TooLow, Unknown };
class GradeException : public std::exception {

    protected:
        Type type;

    public:
        //constructors & destructor
        GradeException() noexcept;
        GradeException(Type _type) noexcept;
        GradeException(const GradeException& other) noexcept;
        GradeException& operator=(const GradeException& other) noexcept;
        virtual ~GradeException();
        //class methods
        virtual const char *what() const noexcept override;
};

#endif
