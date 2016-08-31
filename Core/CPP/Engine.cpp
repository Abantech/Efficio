#include "Engine.h"
#include <iostream>
#include "Enumerations.h"
#include "Vector3.h"
#include "PinchDetector.h"

namespace Efficio {
	Engine::Engine() : started(false), frameID(1)
	{
	}

	Engine::~Engine()
	{
		controller->~Controller();
	}

	void Engine::Start()
	{
		if (DeviceConfiguration.LeapConfiguration.Enabled)
		{
			controller = new Leap::Controller();
		}

		started = true;
	}

	Efficio::EfficioFrame* Engine::GetFrame()
	{
		Efficio::EfficioFrame* efficioFrame = new EfficioFrame(frameID++);

		if (started)
		{
			if (controller != 0)
			{
				auto frame = controller->frame();

				if (frame.isValid())
				{
					
					if (frame.id() == controller->frame(1).id())
					{
						for (size_t i = 0; i < lastFrameEvents.size(); i++)
						{
							efficioFrame->AddEvent(lastFrameEvents[i]);
						}
					}
					else {

						auto hands = frame.hands();

						if (hands.count() > 0)
						{
							for (size_t i = 0; i < hands.count(); i++)
							{
								Efficio::InputRecognition::Human::Hands::PinchDetector detector;
								detector.Enabled = true;
								auto pinches = detector.Detect(hands[i]);

								lastFrameEvents.clear();

								for (size_t j = 0; j < pinches.size(); j++)
								{
									efficioFrame->AddEvent(pinches[j]);
									lastFrameEvents.push_back(pinches[j]);
								}
							}
						}
					}
				}
			}
		}

		historicalFrames.AddFrame(std::shared_ptr<EfficioFrame>(efficioFrame));
		return efficioFrame;
	}
	Efficio::EfficioFrame* Engine::GetFrame(int count)
	{
		auto tempFrame = historicalFrames.GetFrame(count);

		if (tempFrame)
		{
			return historicalFrames.GetFrame(count).get();
		}
		
		return NULL;
	}
}