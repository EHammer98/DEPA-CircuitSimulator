// ComponentFactory.cpp or the appropriate .cpp file

#include "headers/ComponentFactory.h"
#include "headers/BasicComponents.h"  // Include all component headers that you can create
#include "headers/CompositeComponent.h"
#include <iostream>

LogicComponent* ComponentFactory::createComponent(const NodeData& nodeData)
{
    if (nodeData.type == "AND") {
        return new AND(nodeData.name);
    } else if (nodeData.type == "OR") {
        return new OR(nodeData.name);
    } else if (nodeData.type == "NOT") {
        return new NOT(nodeData.name);
    } else if (nodeData.type == "NAND") {
        return new NAND(nodeData.name);
    } else if (nodeData.type == "NOR") {
        return new NOR(nodeData.name);
    } else if (nodeData.type == "XOR") {
        return new XOR(nodeData.name);
    } else if (nodeData.type == "INPUT_HIGH") {
        return new InputHigh(nodeData.name);
    } else if (nodeData.type == "INPUT_LOW") {
        return new InputLow(nodeData.name);
    } else if (nodeData.type == "PROBE") {
        return new Probe(nodeData.name);
    } else if (nodeData.type == "COMPOSITE") {
        return new CompositeComponent();
    }
    // Add additional types as necessary
    return nullptr;  // If the type is unrecognized, return nullptr
}
