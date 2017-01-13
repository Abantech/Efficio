#include "Disconnected.h"

namespace Efficio
{
	namespace Sensors
	{
		Disconnected::Disconnected(Sensors::SensorInformation details) :SensorEvent(details)
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