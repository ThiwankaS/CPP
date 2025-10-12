#include <iostream>
#include <iomanip>

#include "BitcoinExchange.hpp"
#include "Convertor.hpp"

typedef std::chrono::year_month_day Date;

int main(int argc, char *argv[]) {
	if(argc == 2) {

		try {
				BitcoinExchange btc;
				btc.inquirePrices(argv[1]);
    	} catch (const std::exception& e) {
            std::cerr << "Unable to connect the data base! \n";
			std::cerr << e.what() << std::endl;
    	}
    } else {
		std::cerr << "Error: could not open file." << "\n";
	}
    return (EXIT_SUCCESS);

}
