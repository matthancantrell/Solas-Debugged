#pragma once
#include "Framework/Actor.h"

class Enemy : public Solas::Actor
{
public:
	Enemy() = default;
	Enemy(const Solas::Model& model, const Solas::Transform& transform) : Actor{ model, transform }
	{
		Initialize(); // Added
	}

	void Initialize(); // Added
	void Update() override;

private:

	float speed_ = 50;
	float firetimer_ = 10; // Added

};