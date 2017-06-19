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

			Vector3 PinchEvent::Midpoint() 
			{
				auto midX = (Finger1.Tip.Position.x() + Finger2.Tip.Position.x()) / 2;
				auto midY = (Finger1.Tip.Position.y() + Finger2.Tip.Position.y()) / 2;
				auto midZ = (Finger1.Tip.Position.z() + Finger2.Tip.Position.z()) / 2;

				return Vector3(midX, midY, midZ);
			}

			float PinchEvent::Distance() 
			{
				return Finger1.Tip.DistanceTo(Finger2.Tip);
			}

			std::string PinchEvent::GetEventType()
			{
				return PinchEvent::EventType;
			}

			const std::string PinchEvent::EventType = "Pinch";
		}
	}
}