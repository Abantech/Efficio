#pragma once

#include <string>
#include "DiscreteEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	/// A class of events that are raised by sensors
	class SensorEvent : public DiscreteEvent
	{
	public:
		/// @param details Details about the sensor raising the sensor event
		SensorEvent(SensorInformation details);
		~SensorEvent();

		/// Details about the sensor raising the sensor event
		SensorInformation SensorInformation;

		/// Gets the type of event
		virtual std::string GetEventType();
	private:
	};
}