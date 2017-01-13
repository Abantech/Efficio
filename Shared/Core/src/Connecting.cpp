#include "Connecting.h"

namespace Efficio
{
	namespace Sensors
	{
		Connecting::Connecting(Sensors::SensorInformation details) : SensorEvent(details)
		{
		}
		Connecting::~Connecting()
		{
		}
		Events::EventType Connecting::GetEventType()
		{
			return Events::EventType::SensorConnecting;
		}
	}
}