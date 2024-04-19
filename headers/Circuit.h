#pragma once

#include "LogicComponent.h"
#include <vector>

class Circuit {
private:
    std::vector<LogicComponent*> components;
public:
    void compute();
};
