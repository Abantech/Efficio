#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	class Faulted : public SensorEvent
	{
	public:
		Faulted(Efficio::SensorInformation details);
		~Faulted();

		// Inherited via Event
		virtual std::string GetEventType() override;
	};
}