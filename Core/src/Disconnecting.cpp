#include "Disconnecting.h"
namespace Efficio
{
	Disconnecting::Disconnecting(Efficio::SensorInformation details) : SensorEvent(details)
	{
	}
	Disconnecting::~Disconnecting()
	{
	}
	std::string Disconnecting::GetEventType()
	{
		return "SensorDisconnecting";
	}
}
