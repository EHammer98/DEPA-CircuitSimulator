#include "headers/And.h"

#include <iostream>

AND AND::m_cInstance("AND");

void AND::computeOutput() {
    output = input1 && input2;
}

std::string AND::getType() const
{
    return "AND";
}

BasicComponent* AND::clone() const
{
    return new AND;
}
