#pragma once

#include "Sensor.h"
#include "Altimeter.h"
#include "Altitude.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors {
		/// A sample Altimeter
		extern class DLLEXPORT SampleAltimeter : public Efficio::Sensors::Altimeter 
		{
		public:
			SampleAltimeter() {};
			~SampleAltimeter() {};

			/// Gets the asset's current altitude.
			Efficio::Data::Positional::Altitude GetAltitude() { return Efficio::Data::Positional::Altitude(3); }

			void IDoNothing() {};
		};
	}
}