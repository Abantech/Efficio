#pragma once

#include "PinchDetector.h"
#include "PinchEvent.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			PinchDetector::PinchDetector() : IHandEventDetector(){}
			PinchDetector::~PinchDetector() {}

			std::vector<std::shared_ptr<Event>> PinchDetector::DetectEvent(Models::Body::HandData* data)
			{
				std::vector<std::shared_ptr<Event>> events;

				for (size_t i = 0; i < data->Hands.size(); i++)
				{
					auto hand = data->Hands[i];

					for (size_t j = 0; j < 4; j++)
					{
						auto finger1 = hand.Fingers[j];

						for (size_t k = j + 1; k < 5; k++)
						{
							auto distance = finger1.Tip.DistanceTo(hand.Fingers[k].Tip);
							if (distance < 15)
							{
								// TODO get name
								events.push_back(std::shared_ptr<Event>(new PinchEvent("", finger1, hand.Fingers[k], hand.Side)));
							}
						}
					}
				}

				return events;
			}
		}
	}
}