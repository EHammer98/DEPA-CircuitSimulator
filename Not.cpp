#include "headers/Not.h"

#include <iostream>

NOT NOT::m_cInstance("NOT");

void NOT::computeOutput() {
    output = !input1;
}

std::string NOT::getType() const
{
    return "NOT";
}

BasicComponent* NOT::clone() const
{
    return new NOT;
}
