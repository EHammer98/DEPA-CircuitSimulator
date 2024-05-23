#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "headers/FileParser.h"


void FileParser::parse(std::string fileName)
{
    std::ifstream file(fileName);
    std::unordered_map<std::string, NodeType> nodeDescriptions;
    std::vector<Edge> edges;

    if (!file.is_open())
        std::cout << "Failed to open file" << std::endl;

    std::string line;
    bool parsingNodes = true;
    bool parsingEdges = false;
    while (std::getline(file, line)) {
        //  std::cout << "reading line" << std::endl;
        if (line.empty() || line[0] == '#') continue; // skip empty lines and comments

        std::string name;
        std::string typeStr;
        std::istringstream iss(line);
        iss >> name >> typeStr;

        std::cout << typeStr << std::endl;
        if (typeStr == "INPUT_HIGH") nodeDescriptions[name] = NodeType::INPUT_HIGH;
        else if (typeStr == "INPUT_LOW") nodeDescriptions[name] = NodeType::INPUT_LOW;
        else if (typeStr == "PROBE") nodeDescriptions[name] = NodeType::PROBE;
        else if (typeStr == "OR") nodeDescriptions[name] = NodeType::OR;
        else if (typeStr == "AND") nodeDescriptions[name] = NodeType::AND;
        else if (typeStr == "NOT") nodeDescriptions[name] = NodeType::NOT;

    }

    // Now you have the nodes and edges, you can process them as needed
    for (const auto& edge : edges) {
        // Connect nodes as needed
    }

    // Don't forget to deallocate memory for created nodes
    for (const auto& edge : edges) {
        delete edge.from;
        delete edge.to;
    }
}