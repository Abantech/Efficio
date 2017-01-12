#pragma once

#if WINDOWS
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
	namespace Sensors
	{
		enum class DLLEXPORT TrackingType {
			Unknown,
			Hand,
			Eye,
			Face,
			Body,
			Brain,
			Image,
			Audio,
			Speech,
			Location,
			Orientation,
			Analogue
		};
	}
}