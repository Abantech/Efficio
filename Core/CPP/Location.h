#pragma once

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
			/// Class representing location.
			extern class DLLEXPORT Location
			{
			public:
				Location(float latitude, float longitude);
				~Location() {};

				/// The value representing the latitude.  Can be between -180 and 180. 
				const float Latitude() { return latitude; };

				/// The value representing the longitude.  Can be between -90 and 90. 
				const float Longitude() { return longitude; };
			private:
				const float latitude;
				const float longitude;
			};
		}
	}
}