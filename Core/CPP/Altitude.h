#pragma once

#include <string>
#include "Data.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Data
	{
		namespace Positional 
		{
			/// Class representing elevation.
			extern class DLLEXPORT Altitude : public Efficio::Data::Data
			{
			public:
				Altitude(float altitude, std::string unit = "meters") : altitude(altitude), unit(unit) {};
				~Altitude() {};

				/// The value representing the altitude. This measurement is unitless.
				const float GetAltitude() { return altitude; };

				/// The value representing the units for the measurement.
				const std::string UnitOfMeasurement() { return unit; };

				Efficio::Data::DataType GetDataType() { return Efficio::Data::DataType::Altitude; }
			private:
				const float altitude;
				const std::string unit;
			};
		}
	}
}