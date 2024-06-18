#include "headers/Probe.h"

#include <iostream>

PROBE PROBE::m_cInstance("PROBE");

void Probe::observe(BasicComponent* component) {
    observedComponent = component;
}


void PROBE::computeOutput() {
    if (observedComponent != nullptr) {
        output = observedComponent->getOutput();
    }
}

std::string PROBE::getType() const
{
    return "AND";
}

BasicComponent* PROBE::clone() const
{
    return new PROBE;
}