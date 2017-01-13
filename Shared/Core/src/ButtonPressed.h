#pragma once

#include "SensorEvent.h"
#include "ButtonType.h"

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
		class DLLEXPORT ButtonPressed : public Sensors::SensorEvent
		{
		public:
			ButtonPressed(Sensors::SensorInformation details, ButtonType buttonType);
			~ButtonPressed();

			ButtonType ButtonType;

			// Inherited via Event
			virtual Events::EventType GetEventType() override;
		};
	}
}