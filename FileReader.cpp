#include "headers/FileReader.h"
#include <sstream>
#include <fstream>
#include <iostream>

std::stringstream FileReader::readFile(std::string fileName)
{
	std::ifstream file(fileName);

	if (!file.is_open())
		std::cout << "Failed to open file" << std::endl;

	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer;
}