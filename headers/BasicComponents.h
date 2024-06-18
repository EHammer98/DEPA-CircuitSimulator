#pragma once

#include <string>
#include <iostream>
#include "ComponentFactory.h"

class BasicComponent {
	friend class Circuit;
protected:
	BasicComponent* inputComponent1;
	BasicComponent* inputComponent2;
	bool input1;
	bool input2;
	bool output;
	unsigned int numOutputRequests;
	std::string name;


public:
	// Constructor for binary gates
	BasicComponent() {}; // default constructor
	BasicComponent(std::string ID, std::string nameIn) : name(nameIn), input1(false), input2(false), output(false), numOutputRequests(0), inputComponent1(nullptr), inputComponent2(nullptr)
	{
		Factory::ComponentFactory<std::string, BasicComponent>::assign(ID, this);
	}

	void setName(std::string nameIn)
	{
		name = nameIn;
	}

	bool getOutput()
	{
		numOutputRequests++;

		if (numOutputRequests == 1) // first request
		{
			readInputs();
			computeOutput();
		}
		return output;
	}

	std::string getName() {
		return name;
	}

	virtual BasicComponent* clone() const = 0;

private:
	virtual void computeOutput() = 0;

	bool addInputComponent(BasicComponent* inputComp)
	{
		if (inputComponent1 == nullptr) inputComponent1 = inputComp;
		else if (inputComponent2 == nullptr) inputComponent2 = inputComp;
		else return false; // inputs already occupied

		return true;
	}

	void readInputs()
	{
		if (inputComponent1) input1 = inputComponent1->getOutput();
		if (inputComponent2) input2 = inputComponent2->getOutput();
	}

	virtual std::string getType() const { return "none"; } // default type if not overridden
};