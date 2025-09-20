#pragma once

#include <exception>
#include <algorithm>
#include <iterator>
#include <concepts>

struct DataNotFound : public std::exception {
    virtual const char* what() const noexcept {
        return "Requested data not found!";
    }
};

template<typename T>
concept Iterable = requires(T a) {
    { std::begin(a) } -> std::input_or_output_iterator;
    { std::end(a) } -> std::input_or_output_iterator;
};

template <Iterable T>
int easyfind(T& collection, int data) {
    auto it = std::find(collection.begin(), collection.end(), data);
    if(it != collection.end())
        return (*it);
    throw DataNotFound();
}

template <Iterable T>
void print(T& collection) {
    for(auto it = collection.begin();it != collection.end(); it++) {
        std::cout << "element : " << *it << std::endl;
    }
}
