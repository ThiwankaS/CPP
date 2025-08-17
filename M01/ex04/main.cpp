#include <iostream>
#include <string>
#include <fstream>

#include "utilities.hpp"

int main(int argc, char *argv[]) {

	std::string   file_name, s1, s2, line, edited_line;
	std::ifstream in;
	std::ofstream out;

	// return and exit the program when no of aguments incorrect
	if(argc != 4)
	{
		std::cerr << "Incorrect no of arguments! \n";
		return (EXIT_FAILURE);
	}

	// storing arguments values
	file_name = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	// try to open the file and handle file opening error
	in.open(file_name);
	if(!in.is_open()) {
		std::cerr << "Unable to open the file! \n";
		return (EXIT_FAILURE);
	}

	// try to open the destination file or create if not exists
	// handles creating and opening errors also
	out.open(file_name + std::string(".replace"));
	if(!out) {
		in.close();
		std::cerr << "Unable to create the new file! \n";
		return (EXIT_FAILURE);
	}

	// reading the file line by line until the end of the file
	while(std::getline(in, line)) {

		edited_line = replaceAll(line, s1, s2);
		out << edited_line;
		out << "\n";
		edited_line.clear();
	}

	// close file descriptors after use
	in.close();
	out.close();

	// successful message to the user
	std:: cout << "All the occurances of \""
			   << s1
			   << "\" in the file \""
			   << file_name
			   << "\" replaced with \""
			   << s2
			   << "\" and written to the new file \""
			   << file_name + std::string(".replace")
			   << "\" successfully ! \n";
	return (EXIT_SUCCESS);
}
