#include <iostream>
#include <iomanip>

#include "BitcoinExchange.hpp"

int main(void) {

    BitcoinExchange btc;
    try {
            btc.showAll();
    } catch (const std::exception& e) {
            std::cout << "Bad input => \n";
    }
    return (EXIT_SUCCESS);
}
