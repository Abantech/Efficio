#include "Engine.h"
#include "LeapMotion.h"

namespace Efficio {
	Engine::Engine() : started(false), frameID(1)
	{
		sensors.push_back(new Efficio::Sensors::Body::LeapMotion());
	}

	Engine::~Engine()
	{
	}

	void Engine::Start()
	{
		for (size_t i = 0; i < sensors.size(); i++)
		{
			sensors[i]->Connect();
		}
	}

	std::shared_ptr<Efficio::EfficioFrame> Engine::GetFrame()
	{
		std::shared_ptr<Efficio::EfficioFrame> frame(new Efficio::EfficioFrame(frameID++));

		for (size_t i = 0; i < sensors.size(); i++)
		{
			if (sensors[i]->HasFrame())
			{
				frame->AddFrame(sensors[i]->GetFrame());
			}
		}

		return frame;
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