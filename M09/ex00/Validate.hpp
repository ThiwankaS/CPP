#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <regex>

#include "CustomeException.hpp"

typedef std::chrono::year_month_day Date;

#define DEFAULT_DATA_RECORD_FORMAT  "^\\d{4}-\\d{2}-\\d{2},\\d+(\\.\\d+)?$"
#define YEAR    2009
#define MONTH   1
#define DAY     2

constexpr std::chrono::sys_days INITIALE_DATE {
    std::chrono::year{YEAR}/std::chrono::month(MONTH)/std::chrono::day(DAY)
};

class Validate {

    private:
        std::regex      data_format;
        Date            released_date;
        long double     amount_limit;

    public:
        Validate();
        Validate(const Validate& other);
        Validate& operator=(const Validate& other);
        ~Validate();

        struct InvalidFormat : public CustomeException {
            InvalidFormat(const std::string& str)
                : CustomeException(str){}
        };

        struct InvalidDate : public CustomeException {
            InvalidDate(const std::string& msg)
                : CustomeException(msg){}
        };

        struct InvalidAmount : public CustomeException {
            InvalidAmount(const std::string& msg)
                : CustomeException(msg){}
        };

        void setRecordFormat(const std::string& record);
        bool isValidDate(Date date);
        bool isValidRecord(const std::string& record);
        bool isValidAmount(double value);
        bool isPositive(double value);
};

