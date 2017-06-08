#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	/// An event that occurs when a sensor begins to connect
	class Connecting : public SensorEvent
	{
	public:
		Connecting(Efficio::SensorInformation details);
		~Connecting();

		// Inherited via Event
		virtual std::string GetEventType() override;
	};
}