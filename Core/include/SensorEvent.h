#pragma once

#include <string>
#include "DiscreteEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	class SensorEvent : public DiscreteEvent
	{
	public:
		SensorEvent(SensorInformation details);
		~SensorEvent();

		SensorInformation SensorInformation;
		virtual std::string GetEventType() = 0;
	private:
	};
}