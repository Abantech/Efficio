#pragma once

#include "Event.h"
#include <string>
#include "ButtonType.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors
	{
		extern class DLLEXPORT GearVRAction : public Events::Event
		{
		public:
			GearVRAction(Efficio::Sensors::ButtonType buttonType);
			~GearVRAction();
			ButtonType ButtonType;

			virtual Events::EventType GetEventType() override;
		};
	}
}