#pragma once
#include "BasicComponents.h"

class XOR : public BasicComponent
{
public:
	XOR() {} // default constructor
	XOR(std::string ID) : BasicComponent(ID, "") {}
	XOR(std::string ID, std::string nameIn) : BasicComponent(ID, nameIn) {}
	void computeOutput() override;
	std::string getType() const override;

	BasicComponent *clone() const override;

	private:
		static XOR m_cInstance;
};
