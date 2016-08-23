#include "PinchEvent.h"

namespace Efficio
{
	namespace Body
	{
		namespace Hands {
			PinchEvent::PinchEvent(BodySide side, Vector3 position) : side(side), position(position.X(), position.Y(), position.Z())
			{
			}

			PinchEvent::~PinchEvent()
			{
			}
			BodySide PinchEvent::Side()
			{
				return side;
			}
			std::string PinchEvent::Finger1()
			{
				return finger1;
			}
			std::string PinchEvent::Finger2()
			{
				return finger2;
			}
			Efficio::Vector3 PinchEvent::Position()
			{
				return position;
			}
		}
	}
}