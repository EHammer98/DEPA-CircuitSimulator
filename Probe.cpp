// Probe.cpp
#include "headers/Probe.h"

void Probe::observe(LogicComponent* component) {
    observedComponent = component;
}

void Probe::update() {
    if (observedComponent) {
        output = observedComponent->getOutput();
    }
}

bool Probe::getOutput() const {
    return output;
}

void Probe::computeOutput() {
    update();
}
