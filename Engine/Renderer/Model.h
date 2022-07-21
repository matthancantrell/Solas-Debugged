#pragma once
#include "Renderer.h"

#include <vector>
#include <string>

namespace Solas
{
	class Model
	{

	public:

		Model() = default;
		Model(const std::vector<Solas::Vector2>& points, const Solas::Color& color) : points_{ points }, color_{ color } {}
		Model(const std::string& filename);

		void Draw(Solas::Renderer& renderer, const Solas::Vector2& position, float angle, float scale);

		void Load(const std::string& filename);

	private:

		Solas::Color color_;
		std::vector<Solas::Vector2> points_;

	};
}
