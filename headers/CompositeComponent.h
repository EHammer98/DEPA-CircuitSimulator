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
    void addChild(LogicComponent* child) {
        children.push_back(child);
    }

    // Compute output by invoking computeOutput on all child components
    void computeOutput() override {
        // Example logic: Let's say the output is determined by the last child component
        if (!children.empty()) {
            children.back()->computeOutput();
            output = children.back()->getOutput();
        }
    }

    // Get the output of the composite component
    bool getOutput() const override {
        return output;
    }
};
