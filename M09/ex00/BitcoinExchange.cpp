#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
: released_date(INITIALE_DATE) {}

BitcoinExchange::~BitcoinExchange(){}

double BitcoinExchange::getPrice(std::string& date) {
    try {
        std::chrono::year_month_day ymd = toDate(date);
        if(ymd < released_date) {
            throw DataNotFound("Requested data can not find!");
        }
        auto it = data.upper_bound(ymd);
        if(it == data.begin()) {
            throw DataNotFound("Requested data can not find!");
        }
        --it;
        return (it->second);
    } catch (const CustomeException& e) {
        throw;
    }
}
