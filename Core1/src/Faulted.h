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
		extern class DLLEXPORT Faulted : public Events::Event
		{
		public:
			Faulted(SensorInformation details);
			~Faulted();

			SensorInformation SensorInformation;

			// Inherited via Event
			virtual Events::EventType GetEventType() override;
		};
	}
}