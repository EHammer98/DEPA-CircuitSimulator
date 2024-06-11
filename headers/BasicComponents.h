#pragma once

#include "LogicComponent.h"
#include <string>

class BasicComponent : public LogicComponent {
    friend class Circuit;
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

    void setInput1(bool state);
    void setInput2(bool state);

    std::string getType() const override { return "none"; }
};

// AND gate
class AND : public BasicComponent {
public:
    void computeOutput() override;
    std::string getType() const override;
};

// OR gate
class OR : public BasicComponent {
public:
    void computeOutput() override;
    std::string getType() const override;
};

// NOT gate, using input1 for its single input
class NOT : public BasicComponent {
public:
    void computeOutput() override;
    std::string getType() const override;
};

// NAND gate
class NAND : public BasicComponent {
public:
    void computeOutput() override;
    std::string getType() const override;
};

// NOR gate
class NOR : public BasicComponent {
public:
    void computeOutput() override;
    std::string getType() const override;
};

// XOR gate
class XOR : public BasicComponent {
public:
    void computeOutput() override;
    std::string getType() const override;
};

class InputHigh : public BasicComponent {
public:
    void computeOutput() override;
    std::string getType() const override;
};

class InputLow : public BasicComponent {
public:
    void computeOutput() override;
    std::string getType() const override;
};

class Probe : public BasicComponent {
public:
    void observe(BasicComponent* component);
    void computeOutput() override;
    std::string getType() const override;
private:
    BasicComponent* observedComponent;
};