#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <map>

#include "CustomeException.hpp"

#define HEADER_FORMAT       "date,exchange_rate"
#define DATA_RECORD_FORMAT  "^\\d{4}-\\d{2}-\\d{2},\\d+(\\.\\d+)?$"

constexpr std::chrono::sys_days INITIALE_DATE {
    std::chrono::year{2009}/std::chrono::month(1)/std::chrono::day(2)
};

const std::regex data_format(DATA_RECORD_FORMAT);


class Validate {
    private:

    public:
        Validate();
        Validate(const Validate& other) = delete;
        Validate& operator=(const Validate& other) = delete;
        ~Validate();
};

