#pragma once
#pragma once
#include "BasicComponents.h"

class PROBE : public BasicComponent
{
public:
	PROBE() {} // default constructor
	PROBE(std::string ID) : BasicComponent(ID, "") {}
	PROBE(std::string ID, std::string nameIn) : observedComponent(nullptr), BasicComponent(ID, nameIn) {}//
	void computeOutput() override;
	std::string getType() const override;

	void observe(BasicComponent*);

	BasicComponent* clone() const override;

private:
	static PROBE m_cInstance;
	BasicComponent* observedComponent;//
};