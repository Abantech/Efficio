#pragma once

#include "EventType.h"
#include "Event.h"
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
		class DLLEXPORT SensorEvent : public Events::Event
		{
		public:
			SensorEvent(Sensors::SensorInformation details);
			~SensorEvent();

			Sensors::SensorInformation SensorInformation;
			virtual Efficio::Events::EventType GetEventType() = 0;
		private:
		};
	}
}