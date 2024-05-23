#pragma once

// CompositeComponent.h
#include <vector>
#include "LogicComponent.h"

class CompositeComponent : public LogicComponent {
private:
    std::vector<LogicComponent*> children;
    bool output;  // This represents the output of the CompositeComponent

public:
    // Constructor
    CompositeComponent() : output(false) {}

    // Add a child component
    void addChild(LogicComponent* child);

    // Compute output by invoking computeOutput on all child components
    void computeOutput() override;

    // Get the output of the composite component
    bool getOutput() const override;
};
