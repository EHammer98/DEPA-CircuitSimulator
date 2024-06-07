#include "headers/Circuit.h"
#include "headers/ComponentFactory.h"
#include "headers/CompositeComponent.h"
#include "headers/LogicComponent.h"
#include "headers/Probe.h"
//#include "headers/FileParser.h"
#include "headers/FileHandler.h"
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


	//FileParser fileParser;

	Circuit circuit = FileHandler::readAndParse(input_filename);

	/*
	// Simulate the circuit
	circuit.compute();

	// Print results for probes
	for (const auto& comp : components) {
		Probe* probe = dynamic_cast<Probe*>(comp.second);
		if (probe) {
			std::cout << "Probe '" << comp.first << "' output: " << probe->getOutput() << std::endl;
		}
	}
	*/
	return 0;
}
