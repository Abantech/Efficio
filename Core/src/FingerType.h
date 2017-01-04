#pragma once

#if WIN
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
			/// The different finger types
			extern enum class DLLEXPORT FingerType {
				Unknown,
				Thumb,
				Index,
				Middle,
				Ring,
				Pinky
			};
		}
	}
}