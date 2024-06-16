#include "headers/Circuit.h"
#include "headers/ComponentFactory.h"
#include "headers/BasicComponents.h"
#include <iostream>
#include <algorithm>
#include <cctype>

Circuit::Circuit(const std::vector<NodeData>& circuitData) {
	_circuitData = circuitData;

	for (auto& node : circuitData)
	{
		std::cout << "Name: " << node.name << " \tType: " << node.type << "  \t" << node.edges.size() << " Edges: ";

		for (std::string edge : node.edges)
		{
			std::cout << edge << " ";
		}
		std::cout << '\n';
	}

	ComponentFactory factory;

	std::cout << "\nCreating components..." << std::endl;
	for (const auto& node : circuitData) {
		LogicComponent* component = factory.createComponent(node);
		if (component == nullptr) {
			std::cerr << "Failed to create component of type: " << node.type << " for node: " << node.name << std::endl;
		}
		else {
			std::cout << "Created component: " << node.name << " of type: " << node.type << std::endl;
		}


		addComponent(node.name, component);
	}

	connectComponents();
}

void Circuit::connectComponents()
{
	// asign input components to every component

	std::cout << "\nConnecting components..." << std::endl;

	for (auto& node : components)
	{
		BasicComponent* thisComp = dynamic_cast<BasicComponent*>(node.second);

		// get vector of node edges
		std::vector<std::string> edges;

		for (auto& nodeData : _circuitData)
		{
			if (nodeData.name == thisComp->getName()) {
				edges = nodeData.edges;
			}
		}

		std::cout << node.first << " : ";

		// add pointer to this node in each child node

		for (std::string edge : edges) { // loop through outputs
			//{
			// 
			std::cout << " " << edge;
			// find node corresponding to output
			BasicComponent* outputComponent = dynamic_cast<BasicComponent*>(components[edge]);

			if (outputComponent) {
				if (outputComponent->getType() == "Probe") {
					auto probeComp = dynamic_cast<Probe*>(outputComponent);
					probeComp->observe(thisComp);
				}
				else {

					if (outputComponent->addInputComponent(thisComp)) {
						//std::cout << " added input component\n";
					}
				}
			}
		}
		std::cout << std::endl;
	}
}

void Circuit::compute()
{
	std::cout << "\ncompute: \n";

	for (auto& node : components)
	{

		BasicComponent* basicToComponent = dynamic_cast<BasicComponent*>(node.second);

		auto probeComp = dynamic_cast<Probe*>(basicToComponent);

		if (probeComp) // only start calulating from probe components
		{

			bool output = node.second->getOutput();


			//std::cout << "name: " << node.first << " type: " << basicToComponent->getType() << " output: " << output << std::endl;
		}
	}
}

void Circuit::printProbeOutputs()
{
	// Print results for probes
	for (const auto& compPair : components) {
		Probe* probe = dynamic_cast<Probe*>(compPair.second);
		if (probe) {
			std::cout << "Probe '" << compPair.first << "' output: " << probe->getOutput() << std::endl;
		}
	}
}



void Circuit::addComponent(const std::string& name, LogicComponent* component) {
	components[name] = component;
}