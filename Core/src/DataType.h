#pragma once

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
		extern enum class DLLEXPORT DataType 
		{
			None,
			Altitude,
			Location,
			Hand,
			Face
		};
	}
}