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
			/// Representation of a human face
			extern class DLLEXPORT Face
			{
			public:
				Face();
				~Face();
			};
		}
	}
}