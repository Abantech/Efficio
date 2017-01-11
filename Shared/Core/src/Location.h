#pragma once

#include "Data.h"

#if _WINDLL
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
	namespace Data
	{
		namespace Positional
		{
			/// Class representing location.
			class DLLEXPORT Location : public Data
			{
			public:
				Location(float latitude, float longitude);
				~Location() {};

				/// The value representing the latitude.  Can be between -180 and 180. 
				float Latitude() { return latitude; };

				/// The value representing the longitude.  Can be between -90 and 90. 
				float Longitude() { return longitude; };

				DataType GetDataType() { return DataType::Location; }
			private:
				float latitude;
				float longitude;
			};
		}
	}
}