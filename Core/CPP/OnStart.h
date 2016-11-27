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
			/// Event that is raised when the Efficio system starts.
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