#pragma once

#include <string>
#include "Event.h"
#include <time.h>

namespace Efficio
{
	/// An event that takes place over a time period
	class ContinuousEvent : public Event
	{
	public:
		/// @param name The name of the event
		ContinuousEvent(std::string name);
		~ContinuousEvent();

		/// The start time of the event
		time_t StartTime;

		/// How long the event has been occurring
		int Duration();

		/// Gets the type of the event
		virtual std::string GetEventType();
	private:
	};
}