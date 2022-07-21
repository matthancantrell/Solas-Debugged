#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"

namespace Solas
{
	class Scene;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) : GameObject{ transform }, model_{ model }  {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

		friend class Scene; // Added

	private:

	protected:

		bool destroy_ = false; // Added

		Vector2 velocity_; // Added
		float damping_ = 1; // Added

		Scene* scene_ = nullptr; // Moved to protected
		Model model_; // Was here

	};
}
