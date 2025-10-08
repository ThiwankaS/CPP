#include "Validate.hpp"

Validate::Validate()
: data_format(DATA_RECORD_FORMAT), released_date(INITIALE_DATE), header_format(HEADER_FORMAT),
amount_limit(1000.00) {};

Validate::~Validate() {}

void Validate::setHeaderFormat(const std::string& header) {
    this->header_format = header;
}

bool Validate::isValidDate(Date date) {
    return (date.ok() && date >= released_date);
}

bool Validate::isValidRecord(const std::string& record) {
    return (std::regex_match(record, data_format));
}

bool Validate::isValidAmount(double value) {
    return (value <= amount_limit);
}

bool Validate::isValidHeader(const std::string& header) {
    return (header == header_format);
}
