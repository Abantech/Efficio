#pragma once

#include "Face.h"

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
	namespace Models
	{
		namespace Body
		{
			/// Representation of the human head
			class DLLEXPORT Head
			{
			public:
				Head();
				~Head();

				Face GetFace();
			};
		}
	}
}