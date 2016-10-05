#pragma once


#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Data
	{
		extern enum class DLLEXPORT DatumType {
			Altitude,
			Location
		};
	}
}