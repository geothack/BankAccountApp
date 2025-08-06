#pragma once

#include "Source/ImguiBE.h"
#include "Source/States/State.h"

class BusinessAccount : public State
{
public:
	BusinessAccount();
	~BusinessAccount() override;

	void Update() override;
};

