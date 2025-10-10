#include <iostream>
#include <iomanip>

#include "BitcoinExchange.hpp"

int main(void) {

    BitcoinExchange btc;
    try {
            btc.displayRecord("2025-10-07", "10.00", 215.13);
            btc.displayError("not a positive number.");
            btc.displayRecord("2025-10-08", "900.80", 15772.13);
            btc.displayError("bad input => 2001-42-42");
            btc.displayRecord("2025-10-09", "1000.00", 15772.13);
            btc.displayError("too large a number.");
            btc.showAll();
    } catch (const std::exception& e) {
            std::cout << "Bad input => \n";
    }
    return (EXIT_SUCCESS);
}
