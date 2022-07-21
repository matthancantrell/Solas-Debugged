#include "Time.h"

namespace Solas
{
	void Solas::Time::Tick()
	{
		clock_duration duration = clock::now() - startTimePoint_;
		time = duration.count() / (float)clock_duration::period::den;

		duration = clock::now() - frameTimePoint_;
		deltaTime = duration.count() / (float)clock::duration::period::den;

		frameTimePoint_ = clock::now();
	}
}

