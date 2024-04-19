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

    void observe(LogicComponent* component) {
        observedComponent = component;
    }

    void update() {
        if (observedComponent) {
            output = observedComponent->getOutput();
        }
    }

    bool getOutput() const {
        return output;
    }

    void computeOutput() {
        update();
    }
};

#endif // PROBE_H
