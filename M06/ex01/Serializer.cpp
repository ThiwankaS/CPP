#include "Serializer.hpp"

Serializer::Serializer() {
    //nothing doing here
}

Serializer::Serializer(const Serializer& other) {
    //nothing doing here
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    //nothing doing here
    (void)other;
    return (*this);
}

Serializer::~Serializer() {
    //nothing doing here
}

uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}
