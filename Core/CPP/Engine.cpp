#include "Engine.h"
#include <iostream>
#include "PinchEvent.h"
#include "Enumerations.h"

namespace Efficio {
	Engine::Engine() : started(false)
	{
	}

	Engine::~Engine()
	{
		controller->~Controller();
	}

	void Engine::Start()
	{
		if (DeviceConfiguration.GetLeapConfiguration().Enabled)
		{
				controller = new Leap::Controller();
		}

		started = true;
	}

	Efficio::EfficioFrame Engine::GetFrame()
	{
		if (started)
		{
			Efficio::EfficioFrame efficioFrame;

			if (controller != 0)
			{
				auto frame = controller->frame();

				if (frame.isValid())
				{
					auto hands = frame.hands();

					if (hands.count() > 0)
					{
						auto hand = hands.rightmost();

						if (hand.fingers()[0].stabilizedTipPosition().distanceTo(hand.fingers()[1].stabilizedTipPosition()) < 25)
						{
							Body::BodySide side = hand.isLeft() ? Body::BodySide::Left : Body::BodySide::Right;
							auto leapPos = hand.fingers()[0].stabilizedTipPosition();

							auto ib = frame.interactionBox();
							leapPos = ib.normalizePoint(leapPos);

							Vector3 position(leapPos.x, leapPos.y, leapPos.z);
							auto pinch = new Efficio::Body::Hands::PinchEvent(side, position);

							efficioFrame.AddEvent(pinch);
						}

						return efficioFrame;
					}
				}
			}
		}

		Efficio::EfficioFrame frame;
		return frame;
	}
}