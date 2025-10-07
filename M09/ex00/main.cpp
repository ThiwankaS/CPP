#include <iostream>
#include <iomanip>

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if(argc == 2) {
        BitcoinExchange btc;
        std::string date = argv[1];
        try {
                double price = btc.getPrice(date);
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "price : " << price << "\n";
        } catch (const std::exception& e) {
            std::cout << "Bad input => " << date << "\n";
        }
    }
    return (EXIT_SUCCESS);
}
