#include "FileHandler.hpp"

FileHandler::FileHandler()
: file_name(FILE_NAME), header_format(HEADER_FORMAT) {
    readData(FILE_NAME);
}

FileHandler::FileHandler(const std::string& f_name)
: file_name(f_name), header_format(HEADER_FORMAT) {
    readData(f_name);
}

FileHandler::~FileHandler(){
    if(file_name.is_open()) {
        file_name.close();
    }
}

std::map<std::chrono::year_month_day, double>& FileHandler::getData(void) {
    return (this->data);
}

void FileHandler::readData(const std::string& f_name) {
    std::string header, reading_head, date;
    long double price;

    std::getline(file_name, header);
    if(header != header_format)
        throw InvalidHeaderException("Invalid header in the file : " + f_name);
    while(std::getline(file_name, reading_head)) {
        if(!std::regex_match(reading_head, data_format))
            throw InvalidHeaderException("Invalid data in the file : " + f_name);

        std::istringstream obj(reading_head);
        if (!(std::getline(obj, date, ',') && obj >> price) ) {
            throw InvalidHeaderException("Invalid data in the file : " + f_name);
        }
        std::chrono::year_month_day ymd = toDate(date);
        if(price < 0 || price >= std::numeric_limits<double>::max()) {
            throw InvalidHeaderException("Invalid price data in the file : " + f_name);
        }
        auto [it, inserted] = data.emplace(ymd, price);
        if(!inserted)
            throw InvalidHeaderException("Duplicate data in the file : " + f_name);
        reading_head.clear();
    }
}

std::chrono::year_month_day FileHandler::toDate(const std::string& date) {
    std::stringstream obj(date);
    int y, m, d;
    char dash;

    obj >> y >> dash >> m >> dash >> d;
    std::chrono::year_month_day ymd {
        std::chrono::year{y}/std::chrono::month{static_cast<unsigned int>(m)}/std::chrono::day{static_cast<unsigned int>(d)}
    };
    if(!ymd.ok()) {
        throw InvalidDataException("Invalid date data in the file !.");
    }
    return {ymd};
}
