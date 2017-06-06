#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	class Disconnecting : public SensorEvent
	{
	public:
		Disconnecting(Efficio::SensorInformation details);
		~Disconnecting();

		// Inherited via Event
		virtual std::string GetEventType() override;
	};
}