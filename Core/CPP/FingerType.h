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
		namespace Body
		{
			/// The different finger types
			extern enum class DLLEXPORT FingerType {
				Thumb,
				Index,
				Middle,
				Ring,
				Pinky
			};
		}
	}
}