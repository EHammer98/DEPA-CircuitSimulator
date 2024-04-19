#pragma once

#include "LogicComponent.h"

class Probe {
public:
    void observe(LogicComponent* component);
    void update(bool output);
};
