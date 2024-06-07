// Circuit.cpp
#include "headers/Circuit.h"
#include <iostream>
#include "headers/ComponentFactory.h"
#include "headers/BasicComponents.h"



Circuit::Circuit(std::vector<NodeData> circuitData)
{
	/*  for (auto node : circuitData)
	  {
		  std::cout << "Name: " << node.name << " \tType: " << node.type << "  \t" << node.edges.size() << " Edges: ";

		  for (std::string edge : node.edges)
		  {
			  std::cout << edge << " ";
		  }
		  std::cout << '\n';
	  }*/


	ComponentFactory factory;

	for (auto& node : circuitData)
	{
		LogicComponent* component = factory.createComponent(node.type);

	//	if (component != nullptr) std::cout << "Component.type = : " << component->getType() << std::endl;


		addComponent(component);
	}






	std::cout << "Num components: " << components.size() << std::endl;


	for (auto component : components)
	{
		if (component != nullptr) {
			std::cout << "Component.type = : " << component->getType() << std::endl;
		}
		else {
			std::cout << "Component.type = : " << "nullptr" << std::endl;
		}
	}
}




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
