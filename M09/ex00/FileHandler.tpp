#include "FileHandler.hpp"

template <typename key, typename value>
FileHandler<key, value>::FileHandler()
: file_name(FILE_NAME), header_format(HEADER_FORMAT), file_stream() {
}

template <typename key, typename value>
FileHandler<key, value>::FileHandler(const std::string& f_name)
: file_name(f_name), header_format(HEADER_FORMAT), file_stream() {
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
void FileHandler<key, value>::setFileToRead(const std::string& f_name){
    this->file_name = f_name;
}

template <typename key, typename value>
void FileHandler<key, value>::readData(std::map<key,value>& data) {
    std::string header, reading_head, date, closing_price;

    try {
        initializeFileStream();
        std::getline(file_stream, header);
        if(header_format != header){
            throw InvalidFormat("Invalid header in the file : " + file_name);
        }
        while(std::getline(file_stream, reading_head)) {

            std::istringstream obj(reading_head);

            if (!(std::getline(obj, date, ',') && obj >> closing_price) ) {
                throw InvalidFormat("Invalid data in the file : " + file_name);
            }

            auto [it, inserted] = data.emplace(date, closing_price);

            if(!inserted)
                throw InvalidFormat("Duplicate data in the file : " + file_name);
            reading_head.clear();
        }
        file_stream.close();
    } catch (const FileIO& e) {
        std::cerr << "File I/O Error : " << e.what() << std::endl;
    } catch (const InvalidFormat& e) {
        std::cerr << "File Format Error : " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unexpected Error : unknown" << std::endl;
    }
}

template <typename key, typename value>
void FileHandler<key, value>::readData(std::map<key,value>& data, Validate& validator) {
    std::string header, reading_head, date, closing_price;
    Date ymd;
    long double price;

    try {
        initializeFileStream();
        std::getline(file_stream, header);
        if(!validator.isValidHeader(header)){
            throw InvalidFormat("Invalid header in the file : " + file_name);
        }
        while(std::getline(file_stream, reading_head)) {

            if(!validator.isValidRecord(reading_head)){
                throw InvalidFormat("Invalid data in the file : " + file_name);
            }

            std::istringstream obj(reading_head);

            if (!(std::getline(obj, date, ',') && obj >> closing_price) ) {
                throw InvalidFormat("Invalid data in the file : " + file_name);
            }

            ymd = toDate(date);

            if(!validator.isValidDate(ymd)){
                throw InvalidFormat("Invalid date in the file : " + file_name);
            }

            try {
                price = std::stold(closing_price);
            } catch (const std::exception& e) {
                throw;
            }

            if(price < 0 || price >= std::numeric_limits<double>::max()) {
                throw InvalidFormat("Invalid price in the file : " + file_name);
            }

            auto [it, inserted] = data.emplace(ymd, price);

            if(!inserted)
                throw InvalidFormat("Duplicate data in the file : " + file_name);
            reading_head.clear();
        }
        file_stream.close();
    } catch (const FileIO& e) {
        std::cerr << "File I/O Error : " << e.what() << std::endl;
    } catch (const InvalidFormat& e) {
        std::cerr << "File Format Error : " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unexpected Error : unknown" << std::endl;
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
        throw InvalidFormat("Invalid date in the file : " + file_name);
    }
    return {ymd};
}

template <typename key, typename value>
void FileHandler<key, value>::initializeFileStream(void) {
    std::error_code ec;

    if(!std::filesystem::exists(file_name, ec) || ec) {
        throw FileIO("File not exists : " + file_name );
    }

    file_stream.open(file_name);

    if(file_stream.fail()) {
        throw FileIO("Can not open file : " + file_name );
    }

    if(std::filesystem::file_size(file_name) == 0) {
        throw FileIO("Empty file : " + file_name);
    }
}
