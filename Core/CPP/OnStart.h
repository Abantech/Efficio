#pragma once

#include "Event.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Events
	{
		namespace Internal
		{
			/// The abstract class for all events within the Efficio system. Events are raised when anything notable happens within the Efficio ecosystem.
			extern class DLLEXPORT OnStart : public Event
			{
			public:
				OnStart();
				~OnStart();

				// Inherited via Event
				virtual Efficio::Events::EventType GetEventType() override;
			};
		}
	}
}