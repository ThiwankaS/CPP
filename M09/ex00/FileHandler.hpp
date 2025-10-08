#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <map>

#include "CustomeException.hpp"
#include "Validate.hpp"

#define FILE_NAME       "data.csv"
#define HEADER_FROMAT   "date,exchange_rate"

typedef std::chrono::year_month_day Date;

template <typename key, typename value>
class FileHandler {
    protected:
        std::string     file_name;
        std::string     header_format;
        std::ifstream   file_stream;

    public:
        FileHandler();
        FileHandler(const std::string& f_name);
        FileHandler& operator=(const FileHandler& other) = delete;
        FileHandler(const FileHandler& other) = delete;
        virtual ~FileHandler();

        struct FileOpeningException : public CustomeException {
            FileOpeningException(const std::string& str)
                : CustomeException(str){}
        };

        struct EmptyFileExecption : public CustomeException {
            EmptyFileExecption(const std::string& str)
                : CustomeException(str){}
        };

        struct InvalidHeaderException : public CustomeException {
            InvalidHeaderException(const std::string& str)
                : CustomeException(str){}
        };

        struct InvalidDataException : public CustomeException {
            InvalidDataException(const std::string& str)
                : CustomeException(str){}
        };

        void setHeaderFormat(const std::string& header);
        std::map<key,value>& readData(std::map<key,value>& data);
        std::map<key,value>& readData(std::map<key,value>& data, Validate& validator);
        Date toDate(const std::string& date);
};
