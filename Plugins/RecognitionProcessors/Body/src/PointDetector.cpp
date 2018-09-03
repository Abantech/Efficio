#pragma once

#include "PointDetector.h"
#include "PointEvent.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			PointDetector::PointDetector() : IHandEventDetector() {}
			PointDetector::~PointDetector() {}

			std::vector<std::shared_ptr<Event>> PointDetector::DetectEvent(Models::Body::HandData* data)
			{
				std::vector<std::shared_ptr<Event>> events;

				for (size_t i = 0; i < data->Hands.size(); i++)
				{
					auto hand = data->Hands[i];

					if (hand.NumberOfExtendedFingers() == 1 && hand.ExtendedFingerIndicies()[0] == 1)
					{
						events.push_back(std::shared_ptr<Event>(new PointEvent("", hand.Fingers[1], hand.Side)));
					}
				}

				return events;
			}
		}
	}
}