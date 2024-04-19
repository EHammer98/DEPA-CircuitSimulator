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

// AND port
class AND : public BasicComponent {
public:
    void computeOutput() override {
        output = input1 && input2;
    }
};

// OR port
class OR : public BasicComponent {
public:
    void computeOutput() override {
        output = input1 || input2;
    }
};

// NOT port
class NOT : public BasicComponent {
public:
    void computeOutput() override {
        output = !input1;
    }
};

// NAND port
class NAND : public BasicComponent {
public:
    void computeOutput() override {
        output = !(input1 && input2);
    }
};

// NOR port
class NOR : public BasicComponent {
public:
    void computeOutput() override {
        output = !(input1 || input2);
    }
};

// XOR port
class XOR : public BasicComponent {
public:
    void computeOutput() override {
        output = input1 ^ input2;
    }
};