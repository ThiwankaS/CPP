#include "FileHandler.hpp"

FileHandler::FileHandler():
file_name(FILE_NAME),
header_format(DEFAULT_HEADER_FORMAT),
file_stream() {}

FileHandler::FileHandler(const std::string& f_name):
file_name(f_name),
header_format(DEFAULT_HEADER_FORMAT),
file_stream() {}

FileHandler::~FileHandler(){
    if(file_stream.is_open()) {
        file_stream.close();
    }
}

void FileHandler::setFileToRead(const std::string& f_name) {
    this->file_name = f_name;
}

void FileHandler::setHeaderFormat(const std::string& header) {
    this->header_format = header;
}

 bool FileHandler::isValidHeader(const std::string& header) {
    return (this->header_format == header);
 }

void FileHandler::initializeFileStream(void) {
    std::error_code ec;

    if(!std::filesystem::exists(file_name, ec) || ec) {
        throw FileIO("File not exists <" + file_name + ">");
    }

    file_stream.open(file_name);

    if(file_stream.fail()) {
        throw FileIO("Can not open file <" + file_name + ">");
    }

    if(std::filesystem::file_size(file_name) == 0) {
        throw FileIO("Empty file <" + file_name + ">");
    }
}

std::string FileHandler::getNextLine(void) {
    std::string line;

    while(std::getline(file_stream, line)){
        return (line);
    }
    return ("EOF");
}
