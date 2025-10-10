#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    initilizer.readData(data, base_data);
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::displayRecord(
    const std::string& date,
    const std::string& amount,
    double value) {
        std::ostringstream output_string;

        output_string
            << std::left
            << std::setw(10)
            << date
            << " => "
            << std::right
            << std::setw(7)
            << amount
            << " = "
            << std::left
            << std::fixed
            << std::setprecision(2)
            << value;
    std::cout << output_string.str() << std::endl;
}

void BitcoinExchange::displayError(const std::string& message) {
    std::ostringstream output_string;

        output_string
            << std::left
            << std::setw(7)
            << "Error : "
            << std::left
            << message;
    std::cout
        << HIGLIGHT_START
        << output_string.str()
        << HIGLIGHT_END
        << std::endl;
}

// template <typename key, typename value>
// double BitcoinExchange::getPrice(std::string& date) {
//     try {
//         std::chrono::year_month_day ymd = toDate(date);
//         if(ymd < released_date) {
//             throw DataNotFound("Requested data can not find!");
//         }
//         auto it = data.upper_bound(ymd);
//         if(it == data.begin()) {
//             throw DataNotFound("Requested data can not find!");
//         }
//         --it;
//         return (it->second);
//     } catch (const CustomeException& e) {
//         throw;
//     }
// }
