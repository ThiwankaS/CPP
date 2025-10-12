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
#include "Convertor.hpp"

#define HIGLIGHT_START	"\x1b[1m\x1b[38;2;0;0;0m\x1b[48;2;255;255;170m"
#define HIGLIGHT_END	"\x1b[0m"

typedef std::chrono::year_month_day Date;

class BitcoinExchange  {
    private:
        std::map<Date, double> data;
        Convertor convertor;
        FileHandler initilizer;
        FileHandler interface;
        Validate base_data;
        Validate inqure_data;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other) = delete;
        BitcoinExchange& operator=(const BitcoinExchange other) = delete;
        ~BitcoinExchange();

        void displayRecord(Date ymd, double amount, double price);
        void displayError(const std::string& message);
        double getPrice(Date& ymd);
        void inquirePrices(const std::string& f_name);

};
