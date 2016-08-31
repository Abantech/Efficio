#include "Pinch.h"
namespace Efficio {
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hands 
			{
				Pinch::Pinch(Body::BodySide side, Body::Finger finger1, Body::Finger finger2, Vector3 position) : Finger1(finger1), Finger2(finger2), Position(position), Side(side)
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