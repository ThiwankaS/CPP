#include "Convertor.hpp"

Convertor::Convertor() :
delimiter(',') {}

Convertor::~Convertor() {}

double Convertor::toPrice(const std::string& closing_price) {
    long double price;

    try {
            price = std::stod(closing_price);
            if(!isPositive(price)) {
                throw InvalidAmount("not a positive number => " + closing_price);
            }
            return (static_cast<double>(price));
    } catch (const std::out_of_range& e) {
        throw InvalidAmount("too large number => " + closing_price);
    } catch (const std::exception& e) {
        throw InvalidAmount("bad input => " + closing_price);
    }
}

Date Convertor::toDate(const std::string& str) {
    std::stringstream obj(str);
    int y, m, d;
    char dash;

    obj >> y >> dash >> m >> dash >> d;
    std::chrono::year_month_day ymd {
        std::chrono::year{y}/std::chrono::month{static_cast<unsigned int>(m)}/std::chrono::day{static_cast<unsigned int>(d)}
    };
    if(!ymd.ok()) {
        throw InvalidFormat("invalid date => " + str);
    }
    if(!isValidDate(ymd)) {
        throw InvalidFormat("too old date => " + str);
    }
    return {ymd};
}

std::pair<Date, double> Convertor::toRecord(const std::string& str) {
    std::string date_str, price_str;
    Date ymd;
    double price;

    if(!isValidRecord(str)) {
        throw InvalidFormat("bad input => " + str);
    }

    size_t pos = str.find(delimiter);
    date_str = str.substr(0, pos);
    price_str = str.substr(pos + 1);

    try {
        ymd = toDate(date_str);
        price = toPrice(price_str);
        return (std::make_pair(ymd, price));
    } catch (const std::exception& e) {
        throw;
    }
}

void Convertor::setDelimiter(const char& ch) {
    this->delimiter = ch;
}
