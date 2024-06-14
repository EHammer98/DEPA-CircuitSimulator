#include "headers/Circuit.h"
#include "headers/ComponentFactory.h"
#include "headers/CompositeComponent.h"
#include "headers/LogicComponent.h"
#include "headers/BasicComponents.h"
#include "headers/FileHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

int main(int argc, char* argv[]) 
{
  //  std::string input_filename = "circuits/circuit1.txt";

   std::string input_filename = "circuits/fulladder_A1_B1_C1.txt"; // checked all input combinations for full adder


    Circuit circuit = FileHandler::readAndParse(input_filename);

    circuit.compute();


    /*
    // Print results for probes
    for (const auto& compPair : circuit.components) {
        Probe* probe = dynamic_cast<Probe*>(compPair.second);
        if (probe) {
            std::cout << "Probe '" << compPair.first << "' output: " << probe->getOutput() << std::endl;
        }
    }
    */
    return 0;
}
