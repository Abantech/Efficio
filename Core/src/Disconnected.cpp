#include "Disconnected.h"

namespace Efficio
{
	namespace Sensors
	{
		Disonnected::Disonnected(Sensors::SensorInformation details) : SensorInformation(details)
		{
		}
		Disonnected::~Disonnected()
		{
		}
		Events::EventType Disonnected::GetEventType()
		{
			return Events::EventType::SensorDisconnected;
		}
	}
}