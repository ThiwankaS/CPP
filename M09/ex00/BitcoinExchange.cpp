#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::string header, line;

    try {
        initilizer.initializeFileStream();
        header = initilizer.getNextLine();
        if(!initilizer.isValidHeader(header)) {
            throw FileHandler::FileIO("invalid header => " + header);
        }
        while((line = initilizer.getNextLine()) != "EOF") {
            auto [it, inserted] = data.insert(convertor.toRecord(line));
            if(!inserted) {
                throw FileHandler::FileIO("duplicate date => " + line);
            }
            line.clear();
        }
    } catch (const std::exception& e) {
        throw;
    }
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::displayRecord(
    Date ymd,
    double amount,
    double price) {
        std::ostringstream output_string;

        output_string
            << std::setw(4)
            << std::left
            << (int)ymd.year()
            << "-"
            << std::right
            << std::setw(2)
            << std::setfill('0')
            << (unsigned) ymd.month()
            << "-"
            << std::right
            << std::setw(2)
            << std::setfill('0')
            << (unsigned) ymd.day()
            << " => "
            << std::right
            << std::setfill(' ')
            << std::setw(7)
            << std::fixed
            << std::setprecision(2)
            << amount
            << " x "
            << std::right
            << std::setw(10)
            << std::setfill(' ')
            << std::fixed
            << std::setprecision(2)
            << price
            << " = "
            << std::right
            << std::setw(10)
            << std::setfill(' ')
            << std::fixed
            << std::setprecision(2)
            << (price * amount);
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

double BitcoinExchange::getPrice(Date& ymd) {
    auto it = data.upper_bound(ymd);
    --it;
    return (it->second);

}

void BitcoinExchange::inquirePrices(const std::string& f_name) {
    std::string header, line;
    double price;
    std::pair<Date, double> record;

    try {
            interface.setFileToRead(f_name);
            interface.setHeaderFormat("date | value");
            convertor.setRecordFormat("^\\d{4}-\\d{2}-\\d{2}\\s\\|\\s\\d+(\\.\\d+)?$");
            convertor.setDelimiter('|');
            interface.initializeFileStream();
            header = interface.getNextLine();
            if(!interface.isValidHeader(header)) {
                throw FileHandler::FileIO("invalid header => " + header);
            }

            while ((line = interface.getNextLine()) != "EOF") {
                try {
                    record = convertor.toRecord(line);
                    if(!convertor.isValidAmount(record.second)) {
                        throw Convertor::InvalidAmount("too large number => " + line);
                    }
                    price = getPrice(record.first);
                    displayRecord(record.first, record.second, price);
                    line.clear();
                } catch (const Convertor::InvalidDate& e) {
                    displayError(e.what());
                } catch (const Convertor::InvalidFormat& e) {
                    displayError(e.what());
                } catch (const Convertor::InvalidAmount& e) {
                    displayError(e.what());
                }
            }
    } catch (const FileHandler::FileIO& e) {
        displayError(e.what());
    } catch (const std::exception& e) {
        displayError(e.what());
    }
}
