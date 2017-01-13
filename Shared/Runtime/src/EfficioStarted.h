#pragma once

#include "InternalEvent.h"

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
			class DLLEXPORT EfficioStarted : public Efficio::InternalEvent
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