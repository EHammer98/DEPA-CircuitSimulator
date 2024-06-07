#include "headers/FileHandler.h"
#include "headers/FileParser.h"
#include "headers/FileReader.h"
#include <sstream>
#include <iostream>
#include "headers/nodeData.h"


Circuit FileHandler::readAndParse(std::string fileName)
{
	std::stringstream fileStr = FileReader::readFile(fileName);

	std::vector<NodeData> circuitData = FileParser::parse(fileStr);

	return Circuit(circuitData);
}