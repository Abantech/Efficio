#pragma once

#include "DiscreteEvent.h"
#include "BodySide.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			class FistEvent : public DiscreteEvent
			{
			public:
				FistEvent(std::string source, Models::Body::BodySide side);
				~FistEvent();

				Models::Body::BodySide Side;

				std::string GetEventType() override;

				static const std::string EventType;
			};
		}
	}
}