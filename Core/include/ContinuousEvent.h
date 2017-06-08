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
		ContinuousEvent(std::string name);
		~ContinuousEvent();

		time_t StartTime;
		int Duration();

		virtual std::string GetEventType();
	private:
	};
}