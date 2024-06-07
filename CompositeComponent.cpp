// CompositeComponent.cpp
#include "headers/CompositeComponent.h"

    /**
     * Adds a child component to the CompositeComponent.
     *
     * @param child The child component to be added.
     *
     * @throws None
     */
void CompositeComponent::addChild(LogicComponent* child) {
    children.push_back(child);
}

/**
 * Assuming this should compute the output of all children components.
 */
void CompositeComponent::computeOutput() {
    // Assuming this should compute the output of all children components.
    for (auto& child : children) {
        child->computeOutput();
    }
}

    bool CompositeComponent::getOutput() const {
        return false;
    }

   std::string CompositeComponent::getType() const
    {
        return "Composite";
    }