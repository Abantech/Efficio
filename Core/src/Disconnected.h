#pragma once

#include "Event.h"
#include "SensorInformation.h"

#if _WINDLL
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
	namespace Sensors
	{
		extern class DLLEXPORT Disconnected : public Events::Event
		{
		public:
			Disconnected(SensorInformation details);
			~Disconnected();

			SensorInformation SensorInformation;

			// Inherited via Event
			virtual Events::EventType GetEventType() override;
		};
	}
}