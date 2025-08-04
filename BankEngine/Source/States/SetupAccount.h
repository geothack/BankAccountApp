#pragma once

#include "Source/ImguiBE.h"
#include "Source/States/State.h"

class SetupAccount : public State
{
public:
	SetupAccount();
	~SetupAccount() override;

	void Update() override;
};

