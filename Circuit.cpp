#include "headers/Circuit.h"
#include "headers/ComponentFactory.h"
#include "headers/BasicComponents.h"
#include <iostream>

Circuit::Circuit(const std::vector<NodeData>& circuitData) {

    _circuitData = circuitData;

    ComponentFactory factory;

    for (auto& node : circuitData) {
        LogicComponent* component = factory.createComponent(node.type);
        addComponent(node.name, component);
    }

    connectComponents();
}

void Circuit::compute() {
    for (auto& componentPair : components) {
        componentPair.second->computeOutput();
    }
}

void Circuit::addComponent(const std::string& name, LogicComponent* component) {
    components[name] = component;
}

void Circuit::connectComponents() {
    for (const auto& node : _circuitData) {
        LogicComponent* fromComponent = components[node.name];

        for (const auto& edgeName : node.edges) {
            LogicComponent* toComponent = components[edgeName];
            BasicComponent* basicToComponent = dynamic_cast<BasicComponent*>(toComponent);
            if (basicToComponent) {
                if (!basicToComponent->input1) {
                    basicToComponent->setInput1(fromComponent->getOutput());
                    basicToComponent->input1 = true;
                }
                else {
                    basicToComponent->setInput2(fromComponent->getOutput());
                }
            }
        }
    }
}
