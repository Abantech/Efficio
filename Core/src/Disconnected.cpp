#include "Disconnected.h"

namespace Efficio
{
		Disconnected::Disconnected(Efficio::SensorInformation details) :SensorEvent(details)
		{
		}
		Disconnected::~Disconnected()
		{
		}
		std::string Disconnected::GetEventType()
		{
			return "SensorDisconnected";
		}
}