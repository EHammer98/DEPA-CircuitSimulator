#pragma once

// Circuit.h
#include <vector>
#include "LogicComponent.h"

class Circuit {
private:
    std::vector<LogicComponent*> components;

public:
    // Add a component to the circuit
    void addComponent(LogicComponent* component);

    // Compute the output for all components in the circuit
    void compute();
};
