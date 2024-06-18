#pragma once
#include "BasicComponents.h"

class NOR : public BasicComponent
{
public:
	NOR() {} // default constructor
	NOR(std::string ID) : BasicComponent(ID, "") {}
	NOR(std::string ID, std::string nameIn) : BasicComponent(ID, nameIn) {}
	void computeOutput() override;
	std::string getType() const override;

	BasicComponent *clone() const override;

	private:
		static NOR m_cInstance;
};
