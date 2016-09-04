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
								Efficio::Models::Human::Finger finger1 = *(hand.GetFingers().at(i));
								auto finger1Distal = finger1.GetJointPosition(Efficio::Models::Human::JointName::Distal);
								
								Efficio::Models::Human::Finger finger2 = *(hand.GetFingers().at(j));
								auto finger2Distal = finger2.GetJointPosition(Efficio::Models::Human::JointName::Distal);

								if (finger1Distal.DistanceTo(finger2Distal) < 15)
								{
									Efficio::Vector3 position = finger1Distal;
									auto pinch = new Efficio::InputRecognition::Human::Hands::Pinch(hand.Side, finger1.Name, finger2.Name, position);
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