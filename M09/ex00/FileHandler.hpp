#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <map>
#include <limits>

#include "CustomeException.hpp"
#include "Validate.hpp"

#define FILE_NAME       "data.csv"
#define HEADER_FORMAT   "date | value"

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

        struct FileIO : public CustomeException {
            FileIO(const std::string& str)
                : CustomeException(str){}
        };

        struct InvalidFormat : public CustomeException {
            InvalidFormat(const std::string& str)
                : CustomeException(str){}
        };

        void setHeaderFormat(const std::string& header);
        void setFileToRead(const std::string& f_name);
        void readData(std::map<key,value>& data);
        void readData(std::map<key,value>& data, Validate& validator);
        void initializeFileStream(void);
        Date toDate(const std::string& date);
        double toPrice(const std::string& closing_price);
};

#include "FileHandler.tpp"
