#include "Disconnected.h"

namespace Efficio
{
	namespace Sensors
	{
		Disconnected::Disconnected(Sensors::SensorInformation details) : SensorInformation(details)
		{
		}
		Disconnected::~Disconnected()
		{
		}
		Events::EventType Disconnected::GetEventType()
		{
			return Events::EventType::SensorDisconnected;
		}
	}
}