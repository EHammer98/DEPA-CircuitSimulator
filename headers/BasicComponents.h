#pragma once

#include "LogicComponent.h"

class BasicComponent : public LogicComponent {
protected:
    bool input1;
    bool input2;
    bool output;

public:
    // Constructor for binary gates
    BasicComponent() : input1(false), input2(false), output(false) {}

    // Abstract function computeOutput from LogicComponent will be overridden in derived
    virtual void computeOutput() = 0;

    // getOutput implemented here to return the output of the basic component
    bool getOutput() const override { return output; }
};

// AND gate
class AND : public BasicComponent {
public:
    void computeOutput() override;
};

// OR gate
class OR : public BasicComponent {
public:
    void computeOutput() override;
};

// NOT gate, using input1 for its single input
class NOT : public BasicComponent {
public:
    void computeOutput() override;
};

// NAND gate
class NAND : public BasicComponent {
public:
    void computeOutput() override;
};

// NOR gate
class NOR : public BasicComponent {
public:
    void computeOutput() override;
};

// XOR gate
class XOR : public BasicComponent {
public:
    void computeOutput() override;
};
