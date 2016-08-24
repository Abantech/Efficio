#include "PinchEvent.h"

namespace Efficio
{
	namespace Body
	{
		namespace Hands {
			PinchEvent::PinchEvent(BodySide side, Vector3 position) : Side(side), Position(position.X(), position.Y(), position.Z())
			{
			}

			PinchEvent::~PinchEvent()
			{
			}
		}
	}
}