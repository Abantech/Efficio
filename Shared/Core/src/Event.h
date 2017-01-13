#pragma once

#include "EventType.h"
#include <string>
#include <time.h>

#if WINDOWS
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
#define DLLEXPORT
#endif

namespace Efficio 
{
	namespace Events 
	{
		/// The abstract class for all events within the Efficio system. Events are raised when anything notable happens within the Efficio ecosystem.
		class DLLEXPORT Event
		{
		public:
			Event(std::string source);
			~Event();

			time_t Time;

			size_t ID;

			std::string Source;

			virtual Efficio::Events::EventType GetEventType() = 0;
		private:
			static size_t IdIndex;
		};
	}
}