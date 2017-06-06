#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	class Disconnected : public SensorEvent
	{
	public:
		Disconnected(Efficio::SensorInformation details);
		~Disconnected();

		// Inherited via Event
		virtual std::string GetEventType() override;
	};
}