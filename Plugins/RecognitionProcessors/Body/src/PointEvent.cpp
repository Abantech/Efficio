#include "PointEvent.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			PointEvent::PointEvent(std::string source, Models::Body::Finger finger, Models::Body::BodySide side)
				: DiscreteEvent(source), Finger(finger), Side(side), PointDirection(finger.Tip.Position - finger.MCP.Position) { }

			PointEvent::~PointEvent() {}

			std::string PointEvent::GetEventType()
			{
				return PointEvent::EventType;
			}

			const std::string PointEvent::EventType = "Point";
		}
	}
}