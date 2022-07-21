#pragma once
#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h" // Added 

namespace Solas
{
	extern InputSystem inputSystem_g;
	extern Renderer renderer_g;
	extern Time timer_g;
}
