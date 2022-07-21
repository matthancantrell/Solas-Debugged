#include "Player.h"
#include "Engine.h"
#include "Bullet.h" // Added

void Player::Update()
{

	// Rotate Left/Right
	if (Solas::inputSystem_g.GetKeyState(Solas::key_left) == Solas::InputSystem::KeyState::Held)
	{
		transform_.rotation -= (0.05f * Solas::timer_g.deltaTime);
	}

	if (Solas::inputSystem_g.GetKeyState(Solas::key_right) == Solas::InputSystem::KeyState::Held)
	{
		transform_.rotation += (0.05f * Solas::timer_g.deltaTime);
	}

	// Move Forward
	float speed_ = 0; // This is used for drag / dampening (Added)
	if (Solas::inputSystem_g.GetKeyState(Solas::key_up) == Solas::InputSystem::KeyState::Held)
	{
		speed_ = maxSpeed_;
	}

	// Fire Bullet (Added)
	if (Solas::inputSystem_g.GetKeyState(Solas::key_space) == Solas::InputSystem::KeyState::Held)
	{
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(Solas::Model{ "Bullet.txt" }, transform_);
		scene_->Add(std::move(bullet));
	}

/*
	// Mouse
	if (Engine::inputSystem_g.GetButtonState(Engine::button_left) == Engine::InputSystem::KeyState::Pressed)
	{
		std::cout << "Left Mouse Click!" << endl;
	}

	if (Engine::inputSystem_g.GetButtonState(Engine::button_right) == Engine::InputSystem::KeyState::Pressed)
	{
		std::cout << "Mouse Position: (" << Engine::inputSystem_g.GetMousePosition().x << ", " << inputSystem.GetMousePosition().y << ")" << endl;
	}
*/
/*
	// Face Target
	Solas::Vector2 target = Solas::inputSystem_g.GetMousePosition();
	target = target - transform_.position; // Direction Vector Towards
	transform_.rotation = target.GetAngle();
*/

	// Calculate Force (Updated)
	Solas::Vector2 direction{ 1,0 };
	direction = Solas::Vector2::Rotate(direction, transform_.rotation);
	Solas::Vector2 force = direction * speed_ * Solas::timer_g.deltaTime; // Added

	velocity_ += force;

	// Drag (Added)
	velocity_ *= 1.0f / (1.0f + damping_ * Solas::timer_g.deltaTime);
	transform_.position += velocity_ * Solas::timer_g.deltaTime;

	// Wrap (Added)
	if (transform_.position.x > Solas::renderer_g.GetWidth_()) transform_.position.x = 0;
	if (transform_.position.x < 0) transform_.position.x = (float)Solas::renderer_g.GetWidth_();

	if (transform_.position.y > Solas::renderer_g.GetHeight_()) transform_.position.y = 0;
	if (transform_.position.y < 0) transform_.position.y = (float)Solas::renderer_g.GetHeight_();
}
