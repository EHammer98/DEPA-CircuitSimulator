// Circuit.cpp
#include "headers/Circuit.h"


/**
 * Computes the output of all components in the circuit.
 *
 * @throws None
 */
void Circuit::compute() {
    // Iterate through the components and compute each one's output
    for (auto& component : components) {
        component->computeOutput();
    }
}


    /**
     * Adds a LogicComponent to the Circuit.
     *
     * @param component The LogicComponent to be added to the Circuit.
     *
     * @throws None
     */
void Circuit::addComponent(LogicComponent* component) {
    components.push_back(component);
}
