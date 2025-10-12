#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <tuple>

#include "Validate.hpp"
#include "CustomeException.hpp"

typedef std::chrono::year_month_day Date;

class Convertor : public Validate {
    private:
        std::pair<Date, double> record;
        char delimiter;

    public:
        Convertor();
        Convertor(const Convertor& other) = delete;
        Convertor& operator=(const Convertor& other) = delete;
        virtual ~Convertor();

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

        void setDelimiter(const char& ch);
        Date toDate(const std::string& str);
        double toPrice(const std::string& str);
        std::pair<Date, double> toRecord(const std::string& str);
        std::string toString(const Date& ymd);
};
