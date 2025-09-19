#pragma once

#include <iostream>
#include <string>

template<typename T>
class Array {

    private:
        size_t sz;
        T* arr;
        int size;
    public:
        Array();
        Array(size_t size);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
};
