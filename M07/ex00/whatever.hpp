#pragma once

#include <concepts>

template<typename T>
requires std::totally_ordered<T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
requires std::totally_ordered<T>
T min (const T& a, const T& b) {
    return ( a < b ? a : b);
}

template<typename T>
requires std::totally_ordered<T>
T max (const T& a, const T& b) {
     return ( a > b ? a : b);
}
