#pragma once

#include <string>

namespace Efficio
{
	/// The abstract class for all events within the Efficio system. Events are raised when anything notable happens within the Efficio ecosystem.
	class Event
	{
	public:
		Event(std::string source);
		~Event();

		size_t ID;

		std::string Source;

	private:
		static size_t IdIndex;
	};
}