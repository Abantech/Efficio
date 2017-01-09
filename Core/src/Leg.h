#pragma once

#include "BodySide.h"
#include "Joint.h"

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
			/// Representation of the human leg
			extern class DLLEXPORT Leg
			{
			public:
				Leg();
				~Leg();

				BodySide Side;

				Joint Hip;
				Joint Knee;
				Joint Ankle;
				Joint Foot;
			};
		}
	}
}
