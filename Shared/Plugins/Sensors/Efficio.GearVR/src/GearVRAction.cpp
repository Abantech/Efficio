#include "GearVRAction.h"

namespace Efficio
{
	namespace Sensors
	{
		Events::EventType ButtonPressType;

		GearVRAction::GearVRAction(Efficio::Sensors::ButtonType buttonType) : ButtonType(buttonType)
		{
		}

		GearVRAction::~GearVRAction()
		{
		}

		Events::EventType GearVRAction::GetEventType()
		{
			return Events::EventType::ButtonPressed;
		}
	}
}