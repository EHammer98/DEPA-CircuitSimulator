#pragma once
#include "BasicComponents.h"

class NOT : public BasicComponent
{
public:
	NOT() {} // default constructor
	NOT(std::string ID) : BasicComponent(ID, "") {}
	NOT(std::string ID, std::string nameIn) : BasicComponent(ID, nameIn) {}
	void computeOutput() override;
	std::string getType() const override;

	BasicComponent *clone() const override;

	private:
		static NOT m_cInstance;
};
