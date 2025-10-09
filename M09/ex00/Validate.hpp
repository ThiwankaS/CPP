#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <map>

#include "CustomeException.hpp"

typedef std::chrono::year_month_day Date;

#define DEFAULT_HEADER_FORMAT   "date,exchange_rate"
#define DATA_RECORD_FORMAT      "^\\d{4}-\\d{2}-\\d{2},\\d+(\\.\\d+)?$"

constexpr std::chrono::sys_days INITIALE_DATE {
    std::chrono::year{2009}/std::chrono::month(1)/std::chrono::day(2)
};

class Validate {
    private:
        const std::regex    data_format;
        Date                released_date;
        std::string         header_format;
        long double         amount_limit;
    public:
        Validate();
        Validate(const Validate& other) = delete;
        Validate& operator=(const Validate& other) = delete;
        ~Validate();

        void setHeaderFormat(const std::string& header);
        bool isValidDate(Date date);
        bool isValidRecord(const std::string& record);
        bool isValidAmount(double value);
        bool isValidHeader(const std::string& header);
};

