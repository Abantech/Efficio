#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
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
