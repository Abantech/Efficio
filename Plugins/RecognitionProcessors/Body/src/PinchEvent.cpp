#include "PinchEvent.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			PinchEvent::PinchEvent(std::string source, Models::Body::Finger finger1, Models::Body::Finger finger2, Models::Body::BodySide side) 
				: DiscreteEvent(source), Finger1(finger1), Finger2(finger2), Side(side){ }

			PinchEvent::~PinchEvent() {}

			Vector3 PinchEvent::Midpoint() { return Vector3::Midpoint(Finger1.Tip.Position, Finger2.Tip.Position); }

			float PinchEvent::Distance() { return Finger1.Tip.DistanceTo(Finger2.Tip); }

			std::string PinchEvent::GetEventType() { return PinchEvent::EventType; }

			const std::string PinchEvent::EventType = "Pinch";
		}
	}
}