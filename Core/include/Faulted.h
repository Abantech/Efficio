#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	/// An event that occurs when a sensor faults
	class Faulted : public SensorEvent
	{
	public:
		/// @param details The details about sensor raising the event
		Faulted(Efficio::SensorInformation details);
		~Faulted();

		// Inherited via Event
		virtual std::string GetEventType() override;

		static const std::string EventType;
	};
}