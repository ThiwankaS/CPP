#include <iostream>
#include <exception>
#include <string>

#include "iter.hpp"

void multiply_by_two(int &a){
	a = a * 2;
}

void cpitalize(std::string& str) {
	for(size_t i = 0; i < str.length(); i++) {
		str[i] = std::toupper(str[i]);
	}
}

int main (void) {

	int n = 10;
	int* arr = new int[n];

	for(int i = 0; i < n; i++) {
		arr[i] = (i + 1);
	}

	std::cout << "Display initialized values..." << std::endl;
	for(int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] : " << arr[i] << std::endl;
	}
	std::cout << "\n";

	try {
		::iter(arr, n, multiply_by_two);
	} catch (const std::exception& e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << "Display modified values..." << std::endl;
	for(int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] : " << arr[i] << std::endl;
	}
	std::cout << "\n";
	delete [] arr;


	int number = 5;
	std::string* names = new std::string[number]{
		"linus torvalds", "brajane stroustrup", "danish ritche", "ada lovelace", "donald knuth"
	};

	try {
		::iter(names, number, cpitalize);
	} catch (const std::exception& e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << "Display modified values..." << std::endl;
	for(int i = 0; i < number; i++) {
		std::cout << "names [" << i << "] : " << names[i] << std::endl;
	}
	std::cout << "\n";
	
	delete [] names;

    return (EXIT_SUCCESS);
}
