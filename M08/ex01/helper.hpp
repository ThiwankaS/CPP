#pragma once

#include <random>
#include <iostream>

template <typename T>
void print(T& collection) {
    for(auto it = collection.begin();it != collection.end(); it++) {
        std::cout << "element : " << *it << std::endl;
    }
}