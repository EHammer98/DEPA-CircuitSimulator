#include <iostream>
#include "headers/Circuit.h"
#include "headers/ComponentFactory.h"
#include "FileParser.h"
// Other includes


int main() 
{
    std::cout << "Main()" << std::endl;
    // Implementation to read input, create components using factory, simulate and output results

    FileParser fileParser;

    fileParser.parse("circuits/circuit1.txt");

    return 0;
}
