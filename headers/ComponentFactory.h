#pragma once

#include <string>
#include "LogicComponent.h"
#include "headers/nodeData.h"

class ComponentFactory {
public:
    LogicComponent* createComponent(const NodeData&);
};
