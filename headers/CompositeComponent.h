#include "LogicComponent.h"
#include <vector>

class CompositeComponent : public LogicComponent {
private:
    std::vector<LogicComponent*> children;
public:
    void computeOutput() override {
        for (auto& child : children) {
            child->computeOutput();
        }
    }
};
