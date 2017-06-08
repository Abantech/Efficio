#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	/// An event that occurs when a sensor begins to disconnect
	class Disconnecting : public SensorEvent
	{
	public:
		Disconnecting(Efficio::SensorInformation details);
		~Disconnecting();

		// Inherited via Event
		virtual std::string GetEventType() override;
	};
}