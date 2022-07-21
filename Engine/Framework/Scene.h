#pragma once
#include "Actor.h"
#include <list>
#include <memory>

namespace Solas
{
	class Actor;
	class Renderer;

	class Scene
	{
	public:

		Scene() = default;
		~Scene() = default;

		void Update();
		void Draw(Renderer& renderer);
		void Add(std::unique_ptr<Actor> actor);

		// Was added
		template<typename T>
		T* GetActor();

	private:

		std::list<std::unique_ptr<Actor>> actors_;

	};

	// Was added
	template<typename T>
	inline T* Scene::GetActor()
	{
		for (auto& actor : actors_)
		{
			T* result = dynamic_cast<T*>(actor.get());
			if (result) return result;
		}
		return nullptr;
	}

}
