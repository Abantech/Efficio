#include "Connecting.h"

namespace Efficio
{
	namespace Sensors
	{
		Connecting::Connecting(Sensors::SensorInformation details) : SensorInformation(details)
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