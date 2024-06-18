#pragma once
#include "BasicComponents.h"

class NAND : public BasicComponent
{
public:
	NAND() {} // default constructor
	NAND(std::string ID) : BasicComponent(ID, "") {}
	NAND(std::string ID, std::string nameIn) : BasicComponent(ID, nameIn) {}
	void computeOutput() override;
	std::string getType() const override;

	BasicComponent *clone() const override;

	private:
		static NAND m_cInstance;
};
