#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <exception>

struct InvalidRnageRequest : public std::exception {
    virtual const char* what() const noexcept {
        return "Max should be greater than Min!";
    }
};

std::vector<int> generateRandoms(size_t count, int min, int max);
