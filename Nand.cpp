#include "headers/Nand.h"

#include <iostream>

NAND NAND::m_cInstance("NAND");

void NAND::computeOutput() {
    output = !(input1 && input2);
}

std::string NAND::getType() const
{
    return "NAND";
}

BasicComponent* NAND::clone() const
{
    return new NAND;
}
