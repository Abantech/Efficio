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
		// TODO add OnStarted event

		// TODO execute OnStart actions

		// Connect to all sensors
		for (size_t i = 0; i < sensors.size(); i++)
		{
			sensors[i]->Connect();

			// TODO add Device Connected event
		}
	}

	std::shared_ptr<Efficio::Frame> Engine::GetFrame()
	{
		std::shared_ptr<Efficio::Frame> frame(new Efficio::Frame(frameID++));

		// TODO execute BeforeDeviceQuery actions

		// Query sensors for frames
		for (size_t i = 0; i < sensors.size(); i++)
		{
			if (sensors[i]->HasFrame())
			{
				frame->AddFrame(sensors[i]->GetFrame());
			}
		}

		// TODO execute AfterDeviceQuery actions

		// TODO execute BeforeFrameProcess actions

		 auto detectedEvents = ire.ProcessFrame(frame);
		 for (size_t i = 0; i < detectedEvents.size(); i++)
		 {
			 frame->AddEvent(detectedEvents[i]);
		 }

		// TODO execute AfterFrameProcess actions

		return frame;
	}


	std::shared_ptr<Efficio::Frame> Engine::GetFrame(int count)
	{
		auto tempFrame = historicalFrames.GetFrame(count);

		if (tempFrame)
		{
			return historicalFrames.GetFrame(count);
		}

		return NULL;
	}
}