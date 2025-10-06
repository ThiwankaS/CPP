#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <map>

#include "CustomeException.hpp"

#define FILE_NAME           "data.csv"
#define HEADER_FORMAT       "date,exchange_rate"
#define DATA_RECORD_FORMAT  "^\\d{4}-\\d{2}-\\d{2},\\d+(\\.\\d+)?$"

const std::regex data_format(DATA_RECORD_FORMAT);

class FileHandler {
    private:
        std::string header_format;
        std::ifstream file_name;
        std::map<std::chrono::sys_days, double> data;

    public:
        FileHandler();
        FileHandler(const std::string& f_name);
        FileHandler& operator=(const FileHandler& other) = delete;
        FileHandler(const FileHandler& other) = delete;
        ~FileHandler();

        struct FileOpeningException : public CustomeException {
            FileOpeningException(const std::string& message)
                : CustomeException(message){}
        };

        struct EmptyFileExecption : public CustomeException {
            EmptyFileExecption(const std::string& message)
                : CustomeException(message){}
        };

        struct InvalidHeaderException : public CustomeException {
            InvalidHeaderException(const std::string& message)
                : CustomeException(message){}
        };

        struct InvalidDataException : public CustomeException {
            InvalidDataException(const std::string& message)
                : CustomeException(message){}
        };

        void readData(const std::string& f_name);
        std::map<std::chrono::sys_days, double>& getData(void);
};
