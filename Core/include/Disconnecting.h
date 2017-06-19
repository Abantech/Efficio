#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	/// An event that occurs when a sensor begins to disconnect
	class Disconnecting : public SensorEvent
	{
	public:
		/// @param details The details about sensor raising the event
		Disconnecting(Efficio::SensorInformation details);
		~Disconnecting();

		// Inherited via Event
		virtual std::string GetEventType() override;

		static const std::string EventType;
	};
}