#include "ButtonPressed.h"

namespace Efficio
{
	namespace Sensors
	{
		ButtonPressed::ButtonPressed(Sensors::SensorInformation details, Sensors::ButtonType buttonType): SensorEvent(details), ButtonType(buttonType)
		{
		}
		ButtonPressed::~ButtonPressed()
		{
		}
		Events::EventType ButtonPressed::GetEventType()
		{
			return Events::EventType::ButtonPressed;
		}
	}
}