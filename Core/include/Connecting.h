#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	/// An event that occurs when a sensor begins to connect
	class Connecting : public SensorEvent
	{
	public:
		/// @param details The details about sensor raising the event
		Connecting(Efficio::SensorInformation details);
		~Connecting();

		/// Inherited via Event
		virtual std::string GetEventType() override;
	};
}