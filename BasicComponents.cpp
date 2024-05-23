#include "headers/BasicComponents.h"

// AND gate compute function
void AND::computeOutput() {
    output = input1 && input2;
}

// OR gate compute function
void OR::computeOutput() {
    output = input1 || input2;
}

// NOT gate compute function
void NOT::computeOutput() {
    output = !input1;  // Using input1 for NOT gate
}

// NAND gate compute function
void NAND::computeOutput() {
    output = !(input1 && input2);
}

// NOR gate compute function
void NOR::computeOutput() {
    output = !(input1 || input2);
}

// XOR gate compute function
void XOR::computeOutput() {
    output = input1 ^ input2;
}
