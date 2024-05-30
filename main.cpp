#include "headers/Circuit.h"
#include "headers/ComponentFactory.h"
#include "headers/CompositeComponent.h"
#include "headers/LogicComponent.h"
#include "headers/Probe.h"
#include "headers/FileParser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

int main(int argc, char* argv[]) {
	//if (argc < 2) {
	//    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
	//    return 1;
	//}

	//TODO: Change path
	std::string input_filename = "circuits/circuit1.txt"; //argv[1];


	FileParser fileParser;

	auto nodes = fileParser.parse(input_filename);

	// check correctly parsed node data
	for (auto node : nodes)
	{
		std::cout << "Name: " << node.name << " \tType: " << node.type << "  \t" << node.edges.size() << " Edges: ";

		for (std::string edge : node.edges)
		{
			std::cout << edge << " ";
		}
		std::cout << '\n';
	}





	std::ifstream input_file(input_filename);
	if (!input_file.is_open()) {
		std::cerr << "Error: Could not open file " << input_filename << std::endl;
		return 1;
	}

	Circuit circuit;
	ComponentFactory factory;
	std::map<std::string, LogicComponent*> components;
	std::string line;

	// Read and create components
	while (getline(input_file, line)) {
		if (line.empty() || line[0] == '#') continue;
		std::istringstream iss(line);
		std::string node_id, descriptor;
		if (getline(iss, node_id, ':') && getline(iss, descriptor, ';')) {
			LogicComponent* component = factory.createComponent(descriptor);
			if (component) {
				components[node_id] = component;
				circuit.addComponent(component);
			}
		}
	}

	// Reset file read position for connections
	input_file.clear();
	input_file.seekg(0, std::ios::beg);

	// Read connections
	while (getline(input_file, line)) {
		if (line.empty() || line[0] == '#') continue;
		std::istringstream iss(line);
		std::string source_id, target_ids;
		if (getline(iss, source_id, ':') && getline(iss, target_ids)) {
			std::istringstream targets_stream(target_ids);
			std::string target_id;
			while (getline(targets_stream, target_id, ',')) {
				target_id.erase(remove(target_id.begin(), target_id.end(), ' '), target_id.end());
				if (components.count(source_id) && components.count(target_id)) {
					CompositeComponent* composite = dynamic_cast<CompositeComponent*>(components[source_id]);
					if (composite) {
						composite->addChild(components[target_id]);
					}
				}
			}
		}
	}

	// Simulate the circuit
	circuit.compute();

	// Print results for probes
	for (const auto& comp : components) {
		Probe* probe = dynamic_cast<Probe*>(comp.second);
		if (probe) {
			std::cout << "Probe '" << comp.first << "' output: " << probe->getOutput() << std::endl;
		}
	}

	return 0;
}
