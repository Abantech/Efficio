#pragma once

#include "DiscreteEvent.h"
#include "Finger.h"
#include "BodySide.h"
#include "Vector3.h"

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

				Efficio::Vector3 PointDirection;

				std::string GetEventType() override;

				static const std::string EventType;
			};
		}
	}
}