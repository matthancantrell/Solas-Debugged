#pragma once
#include "Framework/Actor.h"

class Bullet : public Solas::Actor
{
public:
	Bullet() = default;
	Bullet(const Solas::Model& model, const Solas::Transform& transform) :
		Actor{ model, transform } {}

	void Update() override;

private:
	float speed_ = 200;
	float lifespan_ = 5; // Added 
};