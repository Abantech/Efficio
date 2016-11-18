#include "Engine.h"

namespace Efficio {
	Engine::Engine() : started(false), frameID(1)
	{
	}

	Engine::~Engine()
	{
	}

	void Engine::Start()
	{

	}

	std::shared_ptr<Efficio::EfficioFrame> Engine::GetFrame()
	{

	}


	std::shared_ptr<Efficio::EfficioFrame> Engine::GetFrame(int count)
	{
		auto tempFrame = historicalFrames.GetFrame(count);

		if (tempFrame)
		{
			return historicalFrames.GetFrame(count);
		}

		return NULL;
	}
}