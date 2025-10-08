#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <map>

#include "CustomeException.hpp"

typedef std::chrono::year_month_day Date;

class FileHandler {
    protected:
        std::ifstream file_name;
        std::map<Date, double> data;

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

        void readData(const std::string& f_name);
        std::map<std::chrono::year_month_day, double>& getData(void);
        std::chrono::year_month_day toDate(const std::string& date);
};
