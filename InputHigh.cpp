#include "headers/InputHigh.h"

#include <iostream>

INPUT_HIGH INPUT_HIGH::m_cInstance("INPUT_HIGH");

void INPUT_HIGH::computeOutput() {
    output = true;
}

std::string INPUT_HIGH::getType() const
{
    return "INPUT_HIGH";
}

BasicComponent* INPUT_HIGH::clone() const
{
    return new INPUT_HIGH;
}
