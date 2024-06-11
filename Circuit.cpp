#include "headers/Circuit.h"
#include "headers/ComponentFactory.h"
#include "headers/BasicComponents.h"
#include <iostream>
#include <algorithm>
#include <cctype>

// Helper function to trim whitespace from both ends of a string
static inline std::string trim(const std::string& s) {
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }
    auto end = s.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

Circuit::Circuit(const std::vector<NodeData>& circuitData) {
    _circuitData = circuitData;

    for (auto node : circuitData)
    {
        std::cout << "Name: " << node.name << " \tType: " << node.type << "  \t" << node.edges.size() << " Edges: ";

        for (std::string edge : node.edges)
        {
            std::cout << edge << " ";
        }
        std::cout << '\n';
    }

    ComponentFactory factory;

    std::cout << "Creating components..." << std::endl;
    for (const auto& node : circuitData) {
        LogicComponent* component = factory.createComponent(node.type);
        if (component == nullptr) {
            std::cerr << "Failed to create component of type: " << node.type << " for node: " << node.name << std::endl;
        }
        else {
            std::cout << "Created component: " << node.name << " of type: " << node.type << std::endl;
        }
        addComponent(node.name, component);
    }

    std::cout << "Connecting components..." << std::endl;
    connectComponents();
}

void Circuit::compute() {
    std::cout << "Computing outputs..." << std::endl;
    for (const auto& componentPair : components) {
        if (componentPair.second == nullptr) {
            std::cerr << "Null component detected for: " << componentPair.first << std::endl;
            continue;
        }
        std::cout << "Computing output for component: " << componentPair.first << std::endl;
        componentPair.second->computeOutput();
    }
}

void Circuit::addComponent(const std::string& name, LogicComponent* component) {
    components[name] = component;
}

void Circuit::connectComponents() {
    for (const auto& node : _circuitData) {
        LogicComponent* fromComponent = components[node.name];
        if (fromComponent == nullptr) {
            std::cerr << "From component is null for node: " << node.name << std::endl;
            continue;
        }

        for (auto edgeName : node.edges) {
            edgeName = trim(edgeName);  // Trim any extra spaces
            LogicComponent* toComponent = components[edgeName];
            if (toComponent == nullptr) {
                std::cerr << "To component is null for edge: " << edgeName << " from node: " << node.name << std::endl;
                continue;
            }
            BasicComponent* basicToComponent = dynamic_cast<BasicComponent*>(toComponent);
            if (basicToComponent) {
                if (!basicToComponent->input1) {
                    std::cout << "Connecting " << node.name << " to " << edgeName << " as input1" << std::endl;
                    basicToComponent->setInput1(fromComponent->getOutput());
                    basicToComponent->input1 = true;
                }
                else {
                    std::cout << "Connecting " << node.name << " to " << edgeName << " as input2" << std::endl;
                    basicToComponent->setInput2(fromComponent->getOutput());
                }
            }
            else {
                std::cerr << "Failed to cast to BasicComponent for edge: " << edgeName << " from node: " << node.name << std::endl;
            }
        }
    }
}
