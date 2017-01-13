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
		class DLLEXPORT Connected : public Sensors::SensorEvent
		{
		public:
			Connected(Sensors::SensorInformation details);
			~Connected();

			// Inherited via Event
			virtual Events::EventType GetEventType() override;
		};
	}
}