// CompositeComponent.h
#include <vector>
#include "LogicComponent.h"

class CompositeComponent : public LogicComponent {
private:
    std::vector<LogicComponent*> children;

public:
    // Add a child component
    void addChild(LogicComponent* child) {
        children.push_back(child);
    }

    // Compute output by invoking computeOutput on all child components
    void computeOutput() override {
        for (auto& child : children) {
            child->computeOutput();
        }
    }
};
