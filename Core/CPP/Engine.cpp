#include "Engine.h"
#include <iostream>
#include "Enumerations.h"
#include "Vector3.h"
#include "RightHandThumbAndIndexPinch.h"

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
		if (DeviceConfiguration.LeapConfiguration.Enabled)
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
							// Get Position
							auto leapPos = hand.fingers()[0].stabilizedTipPosition();
							auto ib = frame.interactionBox();
							leapPos = ib.normalizePoint(leapPos);
							Vector3 position(leapPos.x, leapPos.y, leapPos.z);

							Efficio::InputRecognition::Human::Hand::Pinch* pinch;

							if (hand.isRight())
							{
								pinch = new Efficio::InputRecognition::Human::Hand::RightHandThumbAndIndexPinch(position);
							}
							else
							{
								pinch = new Efficio::InputRecognition::Human::Hand::Pinch(Efficio::Body::BodySide::Left, position);
							}

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