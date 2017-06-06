#include "Faulted.h"

namespace Efficio
{
	Faulted::Faulted(Efficio::SensorInformation details) : SensorEvent(details)
	{
	}

	Faulted::~Faulted()
	{
	}

	std::string Faulted::GetEventType()
	{
		return "SensorFaulted";
	}
}
