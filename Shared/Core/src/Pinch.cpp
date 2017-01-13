#include "Pinch.h"

namespace Efficio 
{
	namespace InputRecognition
	{
		namespace Body
		{
			namespace Hands 
			{
				Pinch::Pinch(std::string source, Efficio::Models::Body::BodySide side, Efficio::Models::Body::Finger finger1, Efficio::Models::Body::Finger finger2) : Side(side), Finger1(finger1), Finger2(finger2), Position(Vector3::Midpoint(finger1.Tip.Position, finger2.Tip.Position)), DiscreteGesture(source)
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