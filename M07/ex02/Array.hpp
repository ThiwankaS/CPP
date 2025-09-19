#pragma once

#include <iostream>
#include <string>
#include <exception>

template<typename T>
class Array {

    private:
        size_t sz;
        T* arr;
    public:
        //constructors && destructors
        Array();
        Array(size_t size);
        Array(const Array& other);
        ~Array();

        //operator overloading
        Array& operator=(const Array& other);
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        
        //array size() operator
        size_t size(void) const;
        
        //exception handling
        struct OutOfBoundsException : public std::exception {
            virtual const char* what() const noexcept {
                return "Index out of bounds";
            }
        };
};

#include "Array.tpp"
