#pragma once
#include "headers/Circuit.h"
#include <string>

class FileHandler
{
public:

	static FileHandler& get_instance() {

		if (instance == nullptr) instance = new FileHandler();

		return *instance;
	}

	Circuit readAndParse(std::string fileName);


	FileHandler(const FileHandler&) = delete;
	FileHandler& operator = (const FileHandler&) = delete;

private:

	FileHandler() = default;
	~FileHandler() = default;

	static FileHandler* instance;
};

