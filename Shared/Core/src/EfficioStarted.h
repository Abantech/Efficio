#pragma once

#include "Event.h"

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
		namespace Internal
		{
			class DLLEXPORT EfficioStarted : public Events::Event
			{
			public:
				EfficioStarted();
				~EfficioStarted();

				// Inherited via Event
				virtual Events::EventType GetEventType() override;

			};
		}
	}
}