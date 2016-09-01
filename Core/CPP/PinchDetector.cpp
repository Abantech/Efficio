#include "PinchDetector.h"
#include "Pinch.h"
#include "Hand.h"

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hands
			{
				std::vector<std::shared_ptr<Gesture>> PinchDetector::Detect(Efficio::Models::Human::Hand hand)
				{
					std::vector<std::shared_ptr<Gesture>> gestures;

					if (Enabled)
					{
						for (size_t i = 0; i < 4; i++)
						{
							for (size_t j = i + 1; j < 5; j++)
							{
								auto finger1Distal = hand.Fingers[i].GetJointPosition("Distal");
								auto finger2Distal = hand.Fingers[j].GetJointPosition("Distal");
								if (finger1Distal.DistanceTo(finger2Distal) < 15)
								{
									Efficio::Vector3 position = finger1Distal;
									auto pinch = new Efficio::InputRecognition::Human::Hands::Pinch(hand.Side, hand.Fingers[i].Name, hand.Fingers[j].Name, position);
									gestures.push_back(std::shared_ptr<Efficio::InputRecognition::Human::Hands::Pinch>(pinch));
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