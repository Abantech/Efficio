#pragma once

#include "Event.h"
#include <string>
#include "ButtonType.h"

#if _WINDLL
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
# else
#define DLLEXPORT 
#endif

namespace Efficio
{
	namespace Sensors
	{
		class DLLEXPORT GearVRAction : public Events::Event
		{
		public:
			GearVRAction(Efficio::Sensors::ButtonType buttonType);
			~GearVRAction();
			ButtonType ButtonType;

			virtual Events::EventType GetEventType() override;
		};
	}
}