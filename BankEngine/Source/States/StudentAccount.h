#pragma once

#include "Source/ImguiBE.h"
#include "Source/States/State.h"

class StudentAccount : public State
{
public:
	StudentAccount();
	~StudentAccount() override;

	void Update() override;
};

