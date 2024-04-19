#pragma once

#include "LogicComponent.h"

class BasicComponent : public LogicComponent {
protected:
    bool input1;
    bool input2;
    bool output;
public:
    virtual void computeOutput() = 0;
};

class AND : public BasicComponent {
public:
    void computeOutput() override {
        output = input1 && input2;
    }
};

// Repeat similar structure for OR, NOT, NAND, NOR, XOR
