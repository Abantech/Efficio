#pragma once

#include "FistDetector.h"
#include "FistEvent.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			FistDetector::FistDetector() : IHandEventDetector() {}
			FistDetector::~FistDetector() {}

			std::vector<std::shared_ptr<Event>> FistDetector::DetectEvent(Models::Body::HandData* data)
			{
				std::vector<std::shared_ptr<Event>> events;

				for (size_t i = 0; i < data->Hands.size(); i++)
				{
					auto hand = data->Hands[i];

					if (hand.NumberOfExtendedFingers() == 0)
					{
						events.push_back(std::shared_ptr<Event>(new FistEvent("", hand.Side)));
					}
				}

				return events;
			}
		}
	}
}