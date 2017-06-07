#pragma once

#include <string>
#include "Event.h"
#include <time.h>

namespace Efficio
{
	class DiscreteEvent : public Event
	{
	public:
		DiscreteEvent(std::string name);
		~DiscreteEvent();

		time_t Time;

		virtual std::string GetEventType();
	private:
	};
}