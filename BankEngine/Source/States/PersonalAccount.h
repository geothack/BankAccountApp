#pragma once

#include "Source/ImguiBE.h"
#include "Source/States/State.h"

class PersonalAccount : public State
{
public:
	PersonalAccount();
	~PersonalAccount() override;

	void Update() override;
};

