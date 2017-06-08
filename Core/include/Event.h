#pragma once

#include <string>

namespace Efficio
{
	/// The abstract class for all events within the Efficio system. Events are raised when anything notable happens within the Efficio ecosystem.
	class Event
	{
	public:
		/// @param source The source of the event
		Event(std::string source);
		~Event();

		/// The unique ID of the event
		size_t ID;

		/// The source of the event
		std::string Source;

	private:
		static size_t IdIndex;
	};
}