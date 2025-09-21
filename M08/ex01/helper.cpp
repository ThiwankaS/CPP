#include "helper.hpp"

std::vector<int> generateRandoms(size_t count, int min, int max) {
    if (min >= max)
        throw InvalidRnageRequest();
    std::vector<int>result;
    result.reserve(count);
    for(size_t i = 0; i < count; i++){
        int value = min + (rand() % (max - min + 1));
        result.push_back(value);
    }
    return (result);
}
