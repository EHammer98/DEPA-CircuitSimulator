#include "headers/Xor.h"

#include <iostream>

XOR XOR::m_cInstance("XOR");

void XOR::computeOutput() {
    output = input1 ^ input2;
}

std::string XOR::getType() const
{
    return "XOR";
}

BasicComponent* XOR::clone() const
{
    return new XOR;
}
