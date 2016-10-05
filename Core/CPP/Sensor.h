#pragma once

#include "DeviceStatus.h"
#include "TrackingType.h"
#include "Vector3.h"
#include "Frame.h"
#include "Leap.h"
#include <string>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors {
		/// Any sensor which can feel data into Efficio
		extern class DLLEXPORT Sensor
		{
		public:
			Sensor() {};
			~Sensor() {};

			/// The unique ID of the device
			std::string ID;

			/// Workaround for necessity of abstract class for dynamic casts
			virtual void IDoNothing() = 0;
		};
	}
}