#pragma once
#pragma once
#include "BasicComponents.h"

class INPUT_HIGH : public BasicComponent
{
public:
	INPUT_HIGH() {} // default constructor
	INPUT_HIGH(std::string ID) : BasicComponent(ID, "") {}
	INPUT_HIGH(std::string ID, std::string nameIn) : BasicComponent(ID, nameIn) {}
	void computeOutput() override;
	std::string getType() const override;

	BasicComponent* clone() const override;

private:
	static INPUT_HIGH m_cInstance;
};
