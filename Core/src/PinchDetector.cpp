#include "PinchDetector.h"
#include "Pinch.h"

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Body
		{
			namespace Hands
			{
				PinchDetector::PinchDetector()
				{
				}

				PinchDetector::~PinchDetector()
				{
				}

				std::vector<std::shared_ptr<Gesture>> PinchDetector::Detect(Models::Body::Hand hand)
				{
					std::vector<std::shared_ptr<Gesture>> pinches;

					for (size_t i = 0; i < 4; i++)
					{
						for (size_t j = i + 1; j < 5; j++)
						{
							if (hand.Fingers[i].Tip.DistanceTo(hand.Fingers[j].Tip) < 25)
							{
								pinches.push_back(std::shared_ptr<Gesture>(new Pinch(hand.Side, hand.Fingers[i], hand.Fingers[j])));
							}
						}
					}

					return pinches;
				}
			}
		}
	}
}
