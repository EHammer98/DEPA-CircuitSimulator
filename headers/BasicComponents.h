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



	void setinputComponent1(BasicComponent* inputComp) { inputComponent1 = inputComp; }
	void setinputComponent2(BasicComponent* inputComp) { inputComponent2 = inputComp; }


	virtual std::string getType() const { return "none"; } // default type if not overridden
};

/*
// OR gate
class OR : public BasicComponent {
public:
	OR(std::string nameIn) : BasicComponent(nameIn) {}
	void computeOutput() override;
	std::string getType() const override;
};

// NOT gate, using input1 for its single input
class NOT : public BasicComponent {
public:
	NOT(std::string nameIn) : BasicComponent(nameIn) {}
	void computeOutput() override;
	std::string getType() const override;
};

// NAND gate
class NAND : public BasicComponent {
public:
	NAND(std::string nameIn) : BasicComponent(nameIn) {}
	void computeOutput() override;
	std::string getType() const override;
};

// NOR gate
class NOR : public BasicComponent {
public:
	NOR(std::string nameIn) : BasicComponent(nameIn) {}
	void computeOutput() override;
	std::string getType() const override;
};

// XOR gate
class XOR : public BasicComponent {
public:
	XOR(std::string nameIn) : BasicComponent(nameIn) {}
	void computeOutput() override;
	std::string getType() const override;
};

class InputHigh : public BasicComponent {
public:
	InputHigh(std::string nameIn) : BasicComponent(nameIn) {}
	void computeOutput() override;
	std::string getType() const override;
};

class InputLow : public BasicComponent {
public:
	InputLow(std::string nameIn) : BasicComponent(nameIn) {}
	void computeOutput() override;
	std::string getType() const override;
};


 
class Probe : public BasicComponent {
public:
	Probe(int ID, std::string nameIn) : observedComponent(nullptr), BasicComponent(ID, nameIn) {}
	void observe(BasicComponent* component);
	void computeOutput() override;
	std::string getType() const override;
private:
	BasicComponent* observedComponent;
};

*/