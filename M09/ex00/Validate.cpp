#include "Validate.hpp"

Validate::Validate():
data_format(DEFAULT_DATA_RECORD_FORMAT),
released_date(INITIALE_DATE),
amount_limit(1000.00) {}

Validate::Validate(const Validate& other):
data_format(other.data_format),
released_date(other.released_date),
amount_limit(other.amount_limit) {}

Validate& Validate::operator=(const Validate& other) {
    if(this != &other) {
        this->data_format = other.data_format;
        this->released_date = other.released_date;
        this->amount_limit = other.amount_limit;
    }
    return (*this);
}

Validate::~Validate() {}

void Validate::setRecordFormat(const std::string& record) {
    this->data_format = record;
}

bool Validate::isValidDate(Date date) {
    return (date.ok() && date >= released_date);
}

bool Validate::isValidRecord(const std::string& record) {
    return (std::regex_match(record, data_format));
}

bool Validate::isValidAmount(double value) {
    return (value < amount_limit && value > 0.0f);
}

bool Validate::isPositive(double value) {
    return (value >= 0.0f);
}
