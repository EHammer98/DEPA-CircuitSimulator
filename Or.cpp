#include "headers/Or.h"

#include <iostream>

OR OR::m_cInstance("OR");

void OR::computeOutput() {
    output = input1 || input2;
}

std::string OR::getType() const
{
    return "OR";
}

BasicComponent* OR::clone() const
{
    return new OR;
}
