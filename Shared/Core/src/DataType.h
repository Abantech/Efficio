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
	namespace Data
	{
		enum class DLLEXPORT DataType 
		{
			None,
			Altitude,
			Location,
			Hand,
			Face
		};
	}
}