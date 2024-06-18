#pragma once
#include "BasicComponents.h"

class INPUT_LOW : public BasicComponent
{
public:
	INPUT_LOW() {} // default constructor
	INPUT_LOW(std::string ID) : BasicComponent(ID, "") {}
	INPUT_LOW(std::string ID, std::string nameIn) : BasicComponent(ID, nameIn) {}
	void computeOutput() override;
	std::string getType() const override;

	BasicComponent* clone() const override;

private:
	static INPUT_LOW m_cInstance;
};
#pragma once
