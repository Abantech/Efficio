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

	std::shared_ptr<Efficio::EfficioFrame> Engine::GetFrame()
	{
		std::shared_ptr<Efficio::EfficioFrame> efficioFrame(new EfficioFrame(frameID++));

		if (started)
		{
			if (controller != 0)
			{
				auto frame = controller->frame();

				if (frame.isValid())
				{
					auto hands = frame.hands();

					if (hands.count() > 0)
					{
						for (size_t i = 0; i < hands.count(); i++)
						{
							Efficio::InputRecognition::Human::Hands::PinchDetector detector;
							detector.Enabled = true;
							auto pinches = detector.Detect(hands[i]);

							for (size_t j = 0; j < pinches.size(); j++)
							{
								efficioFrame->AddEvent(pinches[j]);
							}
						}
					}
				}
			}
		}

		historicalFrames.AddFrame(efficioFrame);
		return efficioFrame;
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