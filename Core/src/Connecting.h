#pragma once

#include "Event.h"
#include "SensorDetails.h"


#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors
	{
		extern class DLLEXPORT Connecting : public Events::Event
		{
		public:
			Connecting(Sensors::SensorInformation details);
			~Connecting();

			SensorInformation SensorInformation;

			// Inherited via Event
			virtual Events::EventType GetEventType() override;
		};
	}
}