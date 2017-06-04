#pragma once

#include <string>
#include <time.h>

namespace Efficio
{
	/// The abstract class for all events within the Efficio system. Events are raised when anything notable happens within the Efficio ecosystem.
	class Event
	{
	public:
		Event(std::string source);
		~Event();

		time_t Time;

		size_t ID;

		std::string Source;

	private:
		static size_t IdIndex;
	};
}