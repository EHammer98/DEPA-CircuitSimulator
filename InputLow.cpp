#include "headers/InputLow.h"

#include <iostream>

INPUT_LOW INPUT_LOW::m_cInstance("INPUT_LOW");

void INPUT_LOW::computeOutput() {
    output = false;
}

std::string INPUT_LOW::getType() const
{
    return "INPUT_LOW";
}

BasicComponent* INPUT_LOW::clone() const
{
    return new INPUT_LOW;
}
