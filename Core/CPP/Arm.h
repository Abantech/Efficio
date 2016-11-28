#pragma once

#include "BodySide.h"
#include "Joint.h"
#include "Hand.h"

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
			/// Representation of a human arm
			extern class DLLEXPORT Arm
			{
			public:
				Arm();
				~Arm();

				BodySide Side;
				Joint Shoulder;
				Joint Elbow;
				Joint Wrist;
				Joint Hand;

				Efficio::Models::Body::Hand GetHand();
			};
		}
	}
}
