#include "Enemy.h"
#include "Engine.h"
#include "Bullet.h"
#include "Player.h"

void Enemy::Initialize() // Added
{
	firetimer_ = Solas::Randomf(2, 6);
	speed_ = Solas::Randomf(20, 100);
}


void Enemy::Update() // Updated
{

	// Fire Weapon

	firetimer_ -= Solas::timer_g.deltaTime;
	if (firetimer_ <= 0)
	{
		firetimer_ = Solas::Randomf(2, 6);
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(Solas::Model{ "Bullet.txt" }, transform_);
		scene_->Add(std::move(bullet));
	}

	// Set Rotation Towards Player
	Player* player = scene_->GetActor<Player>();
	if (player)
	{
		Solas::Vector2 direction = player->transform_.position - transform_.position;
		transform_.rotation = direction.GetAngle();
	}

	// Calculate Velocity

	Solas::Vector2 direction{ 1,0 };
	direction = Solas::Vector2::Rotate(direction, transform_.rotation);

	velocity_ = direction * (speed_ * Solas::timer_g.deltaTime);

	transform_.position += velocity_;

	// Screen Wrapping
	if (transform_.position.x > Solas::renderer_g.GetWidth_()) transform_.position.x = 0;
	if (transform_.position.x < 0) transform_.position.x = (float)Solas::renderer_g.GetWidth_();

	if (transform_.position.y > Solas::renderer_g.GetHeight_()) transform_.position.y = 0;
	if (transform_.position.y < 0) transform_.position.y = (float)Solas::renderer_g.GetHeight_();
}
