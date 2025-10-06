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

std::map<std::chrono::sys_days, double>& FileHandler::getData(void) {
    return (this->data);
}

void FileHandler::readData(const std::string& f_name) {
    std::string header, reading_head, date;
    bool valid_header = false;
    double price;

    std::getline(file_name, header);
    if(!header.empty() || header != header_format)
        throw InvalidHeaderException("Invalid header in the file : " + f_name + "!.");
    if(!header.empty() && header == header_format)
        valid_header = true;
    while(std::getline(file_name, reading_head)) {

        if(header.empty() && reading_head.empty())
            throw EmptyFileExecption("File is empty : " + f_name + "!.");

        if(!header.empty() && reading_head.empty())
            throw InvalidDataException("Invalid data in the file : " + f_name + "!.");

        if(!std::regex_match(reading_head, data_format))
            throw InvalidDataException("Invalid data in the file : " + f_name + "!.");

        std::istringstream obj(reading_head);
        char delimeter;

        if(obj >> date >> delimeter >> price && delimeter == ',') {
            
        } else {
            throw InvalidDataException("Invalid data in the file : " + f_name + "!.");
        }
        reading_head.clear();
    }
}
