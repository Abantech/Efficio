#pragma once

#include "Sensor.h"
#include "Location.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors {
		/// The sensor responsible for reading the asset's location.
		extern class DLLEXPORT LocationSensor : public Efficio::Sensors::Sensor {
		public:
			LocationSensor() {};
			~LocationSensor() {};

			/// Gets the asset's current location.
			virtual Efficio::Data::Positional::Location GetLocation() = 0;
		};
	}
}