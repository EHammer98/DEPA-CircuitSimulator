#pragma once
#include "headers/Circuit.h"
#include <string>

class FileHandler
{
public:
	static Circuit readAndParse(std::string fileName);
};

