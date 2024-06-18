#pragma once
#include "BasicComponents.h"

class AND : public BasicComponent
{
public:
	AND() {} // default constructor
	AND(std::string ID) : BasicComponent(ID, "") {}
	AND(std::string ID, std::string nameIn) : BasicComponent(ID, nameIn) {}
	void computeOutput() override;
	std::string getType() const override;

	BasicComponent *clone() const override;

	private:
		static AND m_cInstance;
};
