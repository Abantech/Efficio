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
		extern class DLLEXPORT Disonnected : public Events::Event
		{
		public:
			Disonnected(SensorDetails details);
			~Disonnected();

			SensorDetails SensorInformation;

			// Inherited via Event
			virtual Events::EventType GetEventType() override;
		};
	}
}