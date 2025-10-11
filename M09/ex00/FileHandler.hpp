#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "CustomeException.hpp"

#define FILE_NAME               "data.csv"
#define DEFAULT_HEADER_FORMAT   "date,exchange_rate"
class FileHandler {

    private:
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

        void setHeaderFormat(const std::string& header);
        void setFileToRead(const std::string& f_name);
        void initializeFileStream(void);
        std::string getNextLine(void);
};
