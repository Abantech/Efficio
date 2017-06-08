#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

namespace Efficio
{
	/// An event that occurs when a sensor connects
	class Connected : public SensorEvent
	{
	public:
		Connected(Efficio::SensorInformation details);
		~Connected();

		// Inherited via Event
		virtual std::string GetEventType() override;
	};
}