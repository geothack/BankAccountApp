#pragma once

#include <vector>

#include "Source/States/State.h"

class StateCache
{
public:
	StateCache()
	{

	}


	template<class T>
	void Add(T& derived)
	{
		auto* base = &static_cast<State&>(derived);

		m_StateCache.push_back(base);
	}

	void Add(State& base)
	{
		m_StateCache.push_back(&base);
	}

	void Update()
	{
		for (auto* state : m_StateCache)
		{
			state->Update();
		}
	}

	void Free()
	{
		m_StateCache.clear();
	}

private:
	std::vector<State*> m_StateCache{};
};
