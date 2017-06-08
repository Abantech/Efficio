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

		/// INform
		SensorInformation SensorInformation;
		virtual std::string GetEventType() = 0;
	private:
	};
}