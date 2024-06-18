#pragma once
#include "BasicComponents.h"

class OR : public BasicComponent
{
public:
	OR() {} // default constructor
	OR(std::string ID) : BasicComponent(ID, "") {}
	OR(std::string ID, std::string nameIn) : BasicComponent(ID, nameIn) {}
	void computeOutput() override;
	std::string getType() const override;

	BasicComponent *clone() const override;

	private:
		static OR m_cInstance;
};
