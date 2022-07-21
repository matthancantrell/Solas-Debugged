#include "Actor.h"

namespace Solas
{
	void Solas::Actor::Draw(Renderer& renderer)
	{
		model_.Draw(renderer, transform_.position, transform_.rotation, transform_.scale);
	}
}

