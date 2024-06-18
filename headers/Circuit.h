#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include <unordered_map>
#include "FileParser.h"
#include "BasicComponents.h"

class Circuit {
public:
    Circuit(const std::vector<NodeData>& circuitData);
    void compute();
    void addComponent(const std::string& name, BasicComponent* component);
    void connectComponents();
    void printProbeOutputs();

private:

    std::unordered_map<std::string, BasicComponent*> components;

    std::vector<NodeData> _circuitData;
};

#endif // CIRCUIT_H
