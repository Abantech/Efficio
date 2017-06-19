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
			class PinchEvent : public DiscreteEvent
			{
			public:
				PinchEvent(std::string source, Models::Body::Finger finger1, Models::Body::Finger finger2, Models::Body::BodySide side);
				~PinchEvent();

				Models::Body::Finger Finger1;
				Models::Body::Finger Finger2;
				Models::Body::BodySide Side;

				Vector3 Midpoint();
				float Distance();

				std::string GetEventType() override;

				static const std::string EventType;
			};
		}
	}
}