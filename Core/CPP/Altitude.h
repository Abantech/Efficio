#pragma once

#include <string>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Models
	{
		namespace Positional 
		{
			/// Class representing elevation.
			extern class DLLEXPORT Altitude
			{
			public:
				Altitude(float altitude, std::string unit = "meters") : altitude(altitude), unit(unit) {};
				~Altitude() {};

				/// The value representing the altitude. This measurement is unitless.
				const float GetAltitude() { return altitude; };

				/// The value representing the units for the measurement.
				const std::string Unit{ return unit; };
			private:
				const float altitude;
				const std::string unit;
			};
		}
	}
}