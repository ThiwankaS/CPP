#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <map>

#include "CustomeException.hpp"
#include "FileHandler.hpp"
#include "Validate.hpp"

class BitcoinExchange : public FileHandler, public Validate {
    private:
        std::chrono::year_month_day released_date;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other) = delete;
        BitcoinExchange& operator=(const BitcoinExchange other) = delete;
        ~BitcoinExchange();

        struct DataNotFound : CustomeException {
            DataNotFound(const std::string& str)
                : CustomeException(str){}
        };

        double getPrice(std::string& date);

        void showData(void) {
            for (const auto& [date, price] : data) {
            std::chrono::year_month_day ymd{date};
            std::cout << static_cast<int>(ymd.year()) << '-'
                  << unsigned(ymd.month()) << '-'
                  << unsigned(ymd.day()) << " | "
                  << price << '\n';
            }
        }
};
