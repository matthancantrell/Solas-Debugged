#include "Bullet.h"
#include "Engine.h"

void Bullet::Update()
{

	// Lifespan (Added)
	lifespan_ -= Solas::timer_g.deltaTime;
	if (lifespan_ <= 0) destroy_ = true;

	// Calculate Velocity

	Solas::Vector2 direction{ 1,0 };
	direction = Solas::Vector2::Rotate(direction, transform_.rotation);

	// Use Member Variable For Velocity (Added)
	velocity_ = direction * (speed_ * Solas::timer_g.deltaTime);
	transform_.position += velocity_;

	// Wrap Added
	if (transform_.position.x > Solas::renderer_g.GetWidth_()) transform_.position.x = 0;
	if (transform_.position.x < 0) transform_.position.x = (float)Solas::renderer_g.GetWidth_();

	if (transform_.position.y > Solas::renderer_g.GetHeight_()) transform_.position.y = 0;
	if (transform_.position.y < 0) transform_.position.y = (float)Solas::renderer_g.GetHeight_();

}
