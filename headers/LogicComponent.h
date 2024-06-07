// LogicComponent.h
#ifndef LOGIC_COMPONENT_H   // If LOGIC_COMPONENT_H is not defined
#define LOGIC_COMPONENT_H   // Define LOGIC_COMPONENT_H

#include <string>

class LogicComponent {
public:
    virtual ~LogicComponent() {}
    virtual void computeOutput() = 0;
    virtual bool getOutput() const = 0;  // Ensure that this method is declared
    virtual std::string getType() const = 0;
};

#endif // LOGIC_COMPONENT_H
