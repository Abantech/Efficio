#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace InputRecognition
	{
		extern enum DLLEXPORT GestureState 
		{
			InProgress,
			Completed
		};
	}
}