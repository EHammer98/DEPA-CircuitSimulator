#pragma once

// Circuit.h
#include <vector>
#include "LogicComponent.h"
#include "headers/NodeData.h"

class Circuit {
private:
    std::vector<LogicComponent*> components;

public:

    Circuit(std::vector<NodeData>);

    // Add a component to the circuit
    void addComponent(LogicComponent* component);

    // Compute the output for all components in the circuit
    void compute();
};
