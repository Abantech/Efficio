#pragma once

#include "DataType.h"
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
			/// Class representing location.
			extern class DLLEXPORT Location : public Efficio::Data::Data
			{
			public:
				Location(float latitude, float longitude);
				~Location() {};

				/// The value representing the latitude.  Can be between -180 and 180. 
				const float Latitude() { return latitude; };

				/// The value representing the longitude.  Can be between -90 and 90. 
				const float Longitude() { return longitude; };

				Efficio::Data::DataType GetDataType() { return Efficio::Data::DataType::Location; }
			private:
				const float latitude;
				const float longitude;
			};
		}
	}
}