#pragma once

#include <iostream>

template<typename T_array, typename T_function>
requires std::invocable<T_function&, T_array&>
void iter(T_array* array, int n, T_function func) {
    for(int i = 0; i < n; i++) {
        func(array[i]);
    }
}

