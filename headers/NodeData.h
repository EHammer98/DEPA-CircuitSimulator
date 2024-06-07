#pragma once
#include <string>
#include <vector>

struct NodeData
{
    std::string name;
    std::string type;
    std::vector<std::string> edges;
};