#include "Connected.h"

namespace Efficio
{
		Connected::Connected(Efficio::SensorInformation details) : SensorEvent(details)
		{
		}
		Connected::~Connected()
		{
		}
		std::string Connected::GetEventType()
		{
			return "SensorConnected";
		}
}