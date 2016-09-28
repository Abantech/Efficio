#include "Pinch.h"
namespace Efficio {
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hands 
			{
				Pinch::Pinch(Body::BodySide side, Efficio::Models::Human::FingerName finger1, Efficio::Models::Human::FingerName finger2, Vector3 position) : Finger1(finger1), Finger2(finger2), Position(position.X(), position.Y(), position.Z()), Side(side)
				{
				}
				Pinch::~Pinch()
				{
				}
				Efficio::Events::EventType Pinch::GetEventType()
				{
					return Efficio::Events::EventType::Pinch;
				}
			}
		}
	}
}