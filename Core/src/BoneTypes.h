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
	namespace Models
	{
		namespace Body
		{
			extern enum class DLLEXPORT BoneType
			{
				/// The bone between the head and center shoulder joint
				Neck,
				UpperSpine,
				LowerSpine,

			};
		}
	}
}