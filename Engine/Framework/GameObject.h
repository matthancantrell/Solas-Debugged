#pragma once
#include "../Math/Transform.h"

namespace Solas
{
	class GameObject
	{
	public:

		GameObject() = default;
		GameObject(const Transform& transform) : transform_{ transform } {}

		virtual void Update() = 0;

		Transform transform_; // Removed GetTransform(), was never used. Maple said to so yeah

	private:

	protected:

		

	};
}