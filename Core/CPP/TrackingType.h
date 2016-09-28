#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	/// Object containing all processed and raw signals
	extern enum class DLLEXPORT TrackingType {
		Unknown,
		Hand,
		Eye, 
		Face,
		Body,
		Mind,
		Image,
		Audio,
		Speech,
		Location,
		Orientation,
		Analogue
	};
}