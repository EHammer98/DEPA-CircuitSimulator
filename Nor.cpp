#include "headers/Nor.h"

#include <iostream>

NOR NOR::m_cInstance("NOR");

void NOR::computeOutput() {
    output = !(input1 || input2);
}

std::string NOR::getType() const
{
    return "NOR";
}

BasicComponent* NOR::clone() const
{
    return new NOR;
}
