#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "test.hpp"

int main(int argc, char *argv[]) {

	std::string file_name, s1, s2, line;
	std::ifstream in;
	std::ofstream out;

	if(argc != 4)
	{
		std::cerr << "Incorrect no of arguments! \n";
		return (EXIT_FAILURE);
	}

	file_name = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	in.open(file_name);
	if(!in.is_open()) {
		std::cerr << "Unable to open the file! \n";
		return (EXIT_FAILURE);
	}

	out.open(file_name + std::string(".replace"));
	if(!out.is_open()) {
		in.close();
		std::cerr << "Unable to create the new file! \n";
		return (EXIT_FAILURE);
	}

	while(true) {
		if(in.eof())
			break;
		std::getline(in, line);
		if(line.empty())
			break;
		std::cout << "line : [" << line << "]\n";
	}

	in.close();
	out.close();
	return (EXIT_SUCCESS);
}
