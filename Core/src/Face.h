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