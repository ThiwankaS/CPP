#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <map>

#include "CustomeException.hpp"
#include "FileHandler.hpp"
#include "Validate.hpp"

typedef std::chrono::year_month_day Date;

class BitcoinExchange  {
    private:
        std::map<Date, double>data;
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
};
