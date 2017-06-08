#pragma once

#include <string>
#include "Event.h"
#include <time.h>

namespace Efficio
{
	/// An event that takes place only once in an instance
	class DiscreteEvent : public Event
	{
	public:
		///@param name The name of the event.
		DiscreteEvent(std::string name);
		~DiscreteEvent();

		/// The time the event was detected
		time_t Time;

		/// Gets the type of event
		virtual std::string GetEventType();
	private:
	};
}