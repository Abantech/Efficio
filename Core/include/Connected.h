#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	/// An event that occurs when a sensor connects
	class Connected : public SensorEvent
	{
	public:
		/// @param details The details about sensor raising the event
		Connected(Efficio::SensorInformation details);
		~Connected();

		/// Inherited via Event
		virtual std::string GetEventType() override;

		static const std::string EventType;
	};
}