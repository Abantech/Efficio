#include "Disconnecting.h"
namespace Efficio
{
	namespace Sensors
	{
		Disconnecting::Disconnecting(Sensors::SensorInformation details) : SensorEvent(details)
		{
		}
		Disconnecting::~Disconnecting()
		{
		}
		Events::EventType Disconnecting::GetEventType()
		{
			return Events::EventType::SensorDisconnecting;
		}
	}
}
