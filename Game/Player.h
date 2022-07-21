#pragma once
#include "Framework/Actor.h"
// Removed Dependencies

class Player : public Solas::Actor
{
public:
	Player() = default;
	Player(const Solas::Model& model, const Solas::Transform& transform) : Actor(model, transform) {}

	void Update() override;

private:
	float speed_{ 0 };
	float maxSpeed_{ 100 };
};

