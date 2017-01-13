#pragma once

#include "SensorEvent.h"
#include "SensorInformation.h"

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
	namespace Sensors
	{
		class DLLEXPORT Disconnecting : public Sensors::SensorEvent
		{
		public:
			Disconnecting(Sensors::SensorInformation details);
			~Disconnecting();

			// Inherited via Event
			virtual Events::EventType GetEventType() override;
		};
	}
}