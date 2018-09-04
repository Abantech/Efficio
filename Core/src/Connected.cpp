#include "Connected.h"

namespace Efficio
{
	Connected::Connected(Efficio::SensorInformation details) : SensorEvent(details) { }
	Connected::~Connected() { }
	std::string Connected::GetEventType() { return Connected::EventType; }
	
	const std::string Connected::EventType = "SensorConnected";
}