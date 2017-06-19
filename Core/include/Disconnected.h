#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	/// An event that occurs when a sensor disconnects
	class Disconnected : public SensorEvent
	{
	public:
		/// @param details The details about sensor raising the event
		Disconnected(Efficio::SensorInformation details);
		~Disconnected();

		// Inherited via Event
		virtual std::string GetEventType() override;

		static const std::string EventType;
	};
}