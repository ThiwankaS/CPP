#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <chrono>
#include <map>

#include "CustomeException.hpp"
#include "FileHandler.hpp"
#include "Validate.hpp"

#define HIGLIGHT_START	"\x1b[1m\x1b[38;2;0;0;0m\x1b[48;2;255;255;170m"
#define HIGLIGHT_END	"\x1b[0m"

typedef std::chrono::year_month_day Date;

class BitcoinExchange  {
    private:
        std::map<Date, double> data;
        std::map<std::string, std::string> buffer;
        FileHandler<Date, double> initilizer;
        FileHandler<std::string, std::string> interface;
        Validate base_data;
        Validate inqure_date;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other) = delete;
        BitcoinExchange& operator=(const BitcoinExchange other) = delete;
        ~BitcoinExchange();

        void displayRecord(const std::string& date, const std::string& amount, double value);
        void displayError(const std::string& message);
        void showAll(void) {
            for(const auto& [d, rate] : data) {
                int y = int(d.year());
                unsigned int m = unsigned(d.month());
                unsigned int dd = unsigned(d.day());
                std::cout << y << "-" << m << "-" << dd << " => " << rate << "\n";
            }
        }
};
