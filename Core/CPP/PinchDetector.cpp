#include "PinchDetector.h"
#include "Pinch.h"

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hands
			{
				std::vector<std::shared_ptr<Gesture>> PinchDetector::Detect(Leap::Hand hand)
				{
					std::vector<std::shared_ptr<Gesture>> gestures;

					if (Enabled)
					{
						for (size_t i = 0; i < 4; i++)
						{
							for (size_t j = i + 1; j < 5; j++)
							{
								if (hand.fingers()[i].stabilizedTipPosition().distanceTo(hand.fingers()[j].stabilizedTipPosition()) < 25)
								{
									Body::BodySide side = hand.isLeft() ? Body::BodySide::Left : Body::BodySide::Right;
									Efficio::Vector3 position(hand.fingers()[i].stabilizedTipPosition().x, hand.fingers()[i].stabilizedTipPosition().y, hand.fingers()[i].stabilizedTipPosition().z);
									Efficio::InputRecognition::Human::Hands::Pinch pinch(side, FingerNames[i], FingerNames[j], position);
									gestures.push_back(std::make_shared<Efficio::InputRecognition::Human::Hands::Pinch>(pinch));
								}
							}
						}
					}

					return gestures;
				}
			}
		}
	}
}