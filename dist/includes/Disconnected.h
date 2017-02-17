#pragma once

#include "Event.h"
#include "SensorInformation.h"


#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
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