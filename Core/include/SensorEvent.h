#pragma once

#include <string>
#include "Event.h"
#include "SensorInformation.h"

namespace Efficio
{
	class SensorEvent : public Event
	{
	public:
		SensorEvent(SensorInformation details);
		~SensorEvent();

		SensorInformation SensorInformation;
		virtual std::string GetEventType() = 0;
	private:
	};
}