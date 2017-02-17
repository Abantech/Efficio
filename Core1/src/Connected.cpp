#include "Connected.h"
namespace Efficio
{
	namespace Sensors
	{
		Connected::Connected(Sensors::SensorInformation details) : SensorInformation(details)
		{
		}
		Connected::~Connected()
		{
		}
		Events::EventType Connected::GetEventType()
		{
			return Events::EventType::SensorConnected;
		}
	}
}