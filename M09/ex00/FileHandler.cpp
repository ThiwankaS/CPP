#include "FileHandler.hpp"

template <typename key, typename value>
FileHandler<key, value>::FileHandler()
: file_name(FILE_NAME), header_format(HEADER_FROMAT), file_stream(FILE_NAME) {
}

template <typename key, typename value>
FileHandler<key, value>::FileHandler(const std::string& f_name)
: file_name(f_name), header_format(HEADER_FROMAT), file_stream(f_name) {
}

template <typename key, typename value>
FileHandler<key, value>::~FileHandler(){
    if(file_stream.is_open()) {
        file_stream.close();
    }
}

template <typename key, typename value>
void FileHandler<key, value>::setHeaderFormat(const std::string& header){
    this->header_format = header;   
}

template <typename key, typename value>
std::map<key,value>& FileHandler<key, value>::readData(std::map<key,value>& data, Validate& validator) {
    std::string header, reading_head, date, closing_price;
    Date ymd;
    long double price;

    std::getline(file_stream, header);
    if(!validator.isValidHeader(header))
        throw InvalidHeaderException("Invalid header in the file : " + file_name);
    while(std::getline(file_stream, reading_head)) {

        if(!validator.isValidRecord(reading_head))
            throw InvalidHeaderException("Invalid data in the file : " + file_name);

        std::istringstream obj(reading_head);

        if (!(std::getline(obj, date, ',') && obj >> closing_price) ) {
            throw InvalidHeaderException("Invalid data in the file : " + file_name);
        }

        ymd = toDate(date);
        
        if(!validator.isValidDate(ymd)){
            throw InvalidHeaderException("Invalid price data in the file : " + file_name);
        }

        try {
            price = std::stold(closing_price);
        } catch (const std::exception& e) {
            throw;
        }

        if(price < 0 || price >= std::numeric_limits<double>::max()) {
            throw InvalidHeaderException("Invalid price data in the file : " + file_name);
        }

        auto [it, inserted] = data.emplace(ymd, price);

        if(!inserted)
            throw InvalidHeaderException("Duplicate data in the file : " + file_name);
        reading_head.clear();
    }
}

template <typename key, typename value>
Date FileHandler<key, value>::toDate(const std::string& date) {
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
