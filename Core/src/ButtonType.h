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
	namespace Sensors 
	{
		extern enum class DLLEXPORT ButtonType
		{
			Up,
			Down,
			Left,
			Right,
			Back
		};
	}
}
