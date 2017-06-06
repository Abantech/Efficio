#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	class Connecting : public SensorEvent
	{
	public:
		Connecting(Efficio::SensorInformation details);
		~Connecting();

		// Inherited via Event
		virtual std::string GetEventType() override;
	};
}