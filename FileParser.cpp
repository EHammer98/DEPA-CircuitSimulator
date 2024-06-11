#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "headers/FileParser.h"



std::vector<NodeData> FileParser::parse(std::stringstream & fileStr)
{
	std::vector<NodeData> nodes;
	bool parsingNodes = true; // parsing edges when false

	std::string line;

	while (std::getline(fileStr, line)) {
		//std::cout << "reading line: " << line << std::endl;
		if (line.find("# Description of all the edges") != std::string::npos) {
			parsingNodes = false;
			//	std::cout << "\nPARSING EDGES FROM HERE ON\n\n";
			continue;
		}
		else if (line.empty() || line[0] == '#') continue; // skip empty lines and comments


		if (parsingNodes)
		{
			size_t colonPos = line.find(':');
			std::string name = line.substr(0, colonPos);

			size_t typeStartPos = line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ",colonPos +1);

			size_t semiColonPos = line.find(';', typeStartPos + 1);
			std::string typeStr = line.substr(typeStartPos, semiColonPos - typeStartPos);

			//std::cout << "name: " << name << "           Type :" << typeStr << std::endl;

			nodes.push_back(NodeData{ name, typeStr, std::vector<std::string>() });
		}
		else { // parsing edges


			size_t colonPos = line.find(':');
			std::string name = line.substr(0, colonPos);

			//	std::cout << name << "\t";

			size_t lastPos = colonPos;


			std::vector<std::string>* edgesVec = nullptr;

			for (auto &node : nodes)
			{
				if (node.name == name) {
					//	std::cout << "Set vector\n";
					edgesVec = &node.edges;
				}
			}

			if (edgesVec == nullptr) {
				std::cout << "Error setting vector\n";
				return std::vector<NodeData>();
			}

			lastPos = line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ", lastPos + 1);

			while (true) {

				size_t seperatorPos = line.find_first_of(",;", lastPos + 1);
				if (seperatorPos == std::string::npos) break;

				std::string edgeNode = line.substr(lastPos, seperatorPos - lastPos);

				edgesVec->push_back(edgeNode);

				//		std::cout << " " << edgeNode;
				lastPos = seperatorPos+1;
			}
			//	std::cout << '\n';
		}
	}
	return nodes;
}