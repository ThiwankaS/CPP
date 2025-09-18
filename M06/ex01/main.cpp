#include <iostream>

#include "Serializer.hpp"
#include "Data.hpp"
#include "test.hpp"

int main (void) {

	Data* ptr = new Data;

	ptr->id		= 1;
	ptr->name	= "Jhon Doily";
	ptr->age	= 37;

	test("Print data using a pointer : ");
	LINE_DATA;
	std::cout << "ptr -> id :" << ptr->id << std::endl;
	std::cout << "ptr -> name :" << ptr->name << std::endl;
	std::cout << "ptr -> age :" << ptr->age << std::endl;

	uintptr_t raw = Serializer::serialize(ptr);
	Data* serialized = Serializer::deserialize(raw);

	test("Print pointer/varibale values : ");
	LINE_DATA;
	std::cout << "ptr			:" << ptr << std::endl;
	std::cout << "raw			:" << raw << std::endl;
	std::cout << "serialized		:" << serialized << std::endl;

	test("Print data using a raw pointer (after serialize) : ");
	LINE_DATA;
	std::cout << "serialized -> id :" << serialized->id << std::endl;
	std::cout << "serialized -> name :" << serialized->name << std::endl;
	std::cout << "serialized -> age :" << serialized->age << std::endl;
    return (EXIT_SUCCESS);
}
