// ComponentFactory.cpp or the appropriate .cpp file

#include "headers/ComponentFactory.h"
#include "headers/BasicComponents.h"  // Include all component headers that you can create
#include "headers/CompositeComponent.h"
// ... include other necessary headers ...

LogicComponent* ComponentFactory::createComponent(const std::string& type) {
    if (type == "AND") {
        return new AND();
    } else if (type == "OR") {
        return new OR();
    } else if (type == "NOT") {
        return new NOT();
    } else if (type == "NAND") {
        return new NAND();
    } else if (type == "NOR") {
        return new NOR();
    } else if (type == "XOR") {
        return new XOR();
    } else if (type == "Composite") {
        return new CompositeComponent();
    }
    // Add additional types as necessary

    return nullptr;  // If the type is unrecognized, return nullptr
}
