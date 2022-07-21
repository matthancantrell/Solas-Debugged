#include "Memory.h"

namespace Solas
{

	void initializeMemory()
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	}

}

