#include "Disconnecting.h"
namespace Efficio
{
	namespace Sensors
	{
		Disonnecting::Disonnecting(Sensors::SensorInformation details) : SensorEvent(details)
		{
		}
		Disonnecting::~Disonnecting()
		{
		}
		Events::EventType Disonnecting::GetEventType()
		{
			return Events::EventType::SensorDisconnecting;
		}
	}
}
