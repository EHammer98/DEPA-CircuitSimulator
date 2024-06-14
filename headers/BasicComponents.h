#pragma once

#include "LogicComponent.h"
#include <string>

class BasicComponent : public LogicComponent {
	friend class Circuit;
protected:
	BasicComponent* inputComponent1;
	BasicComponent* inputComponent2;
	bool input1;
	bool input2;
	bool output;
	std::string name;

public:
	// Constructor for binary gates
	BasicComponent(std::string nameIn) : name(nameIn), input1(false), input2(false), output(false) {}



	// Abstract function computeOutput from LogicComponent will be overridden in derived
	virtual void computeOutput() = 0;


	std::string getName() {
		return name;
	}

	// getOutput implemented here to return the output of the basic component


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

	bool getOutput() override 
	{
		readInputs();

		computeOutput();

		return output;
	}

	void setInput1(bool state);
	void setInput2(bool state);

	void setinputComponent1(BasicComponent* inputComp) { inputComponent1 = inputComp; }
	void setinputComponent2(BasicComponent* inputComp) { inputComponent2 = inputComp; }


	std::string getType() const override { return "none"; }
};

// AND gate
class AND : public BasicComponent {
public:
	AND(std::string nameIn) : BasicComponent(nameIn) {}
	void computeOutput() override;
	std::string getType() const override;
};

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
	Probe(std::string nameIn) : observedComponent(nullptr), BasicComponent(nameIn){}
	void observe(BasicComponent* component);
	void computeOutput() override;
	std::string getType() const override;
private:
	BasicComponent* observedComponent;
};