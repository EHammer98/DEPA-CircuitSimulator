#include <string>
#include "LogicComponent.h"

class ComponentFactory {
public:
    LogicComponent* createComponent(const std::string& type);
};
