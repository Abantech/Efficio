#pragma once

#include "Sensor.h"
#include "Altitude.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors {
		/// The sensor responsible for reading the asset's altitude.
		extern class DLLEXPORT Altimeter : public Efficio::Sensors::Sensor{
		public:
			Altimeter() {};
			~Altimeter() {};

			/// Gets the asset's current altitude.
			virtual Efficio::Data::Positional::Altitude GetAltitude() = 0;
		};
	}
}