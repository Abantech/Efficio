#pragma once

#include "DiscreteEvent.h"
#include "Finger.h"
#include "BodySide.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			class PointEvent : public DiscreteEvent
			{
			public:
				PointEvent(std::string source, Models::Body::Finger finger, Models::Body::BodySide side);
				~PointEvent();

				Models::Body::Finger Finger;
				Models::Body::BodySide Side;

				// TODO point direction vecto;

				std::string GetEventType() override;

				static const std::string EventType;
			};
		}
	}
}