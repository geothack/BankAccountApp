#pragma once


class State
{
public:
	State() = default;
	virtual ~State() {};

	virtual void Update() = 0;

	bool IsActive = false;
};