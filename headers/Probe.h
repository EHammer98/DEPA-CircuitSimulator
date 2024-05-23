// Probe.h
#ifndef PROBE_H
#define PROBE_H

#include "LogicComponent.h"

class Probe {
private:
    LogicComponent* observedComponent;
    bool output;

public:
    Probe() : observedComponent(nullptr), output(false) {}

    void observe(LogicComponent* component);

    void update();

    bool getOutput() const;

    void computeOutput();
};

#endif // PROBE_H
