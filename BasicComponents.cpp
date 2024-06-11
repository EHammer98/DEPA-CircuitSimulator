#include "headers/BasicComponents.h"
#include <string>

// AND gate compute function
void AND::computeOutput() {
    output = input1 && input2;
}

std::string AND::getType() const
{
    return "AND";
}

// OR gate compute function
void OR::computeOutput() {
    output = input1 || input2;
}

std::string OR::getType() const
{
    return "OR";
}

// NOT gate compute function
void NOT::computeOutput() {
    output = !input1;  // Using input1 for NOT gate
}
std::string NOT::getType() const
{
    return "NOT";
}

// NAND gate compute function
void NAND::computeOutput() {
    output = !(input1 && input2);
}
std::string NAND::getType() const
{
    return "NAND";
}

// NOR gate compute function
void NOR::computeOutput() {
    output = !(input1 || input2);
}

std::string NOR::getType() const
{
    return "NOR";
}

// XOR gate compute function
void XOR::computeOutput() {
    output = input1 ^ input2;
}

std::string XOR::getType() const
{
    return "XOR";
}

void InputHigh::computeOutput() {
    output = true;
}

std::string InputHigh::getType() const
{
    return "InputHigh";
}

void InputLow::computeOutput() {
    output = false;
}

std::string InputLow::getType() const
{
    return "InputLow";
}

void Probe::observe(BasicComponent* component) {
    observedComponent = component;
}

std::string Probe::getType() const
{
    return component;
}
