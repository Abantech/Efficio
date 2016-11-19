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

				const BodySide Side;
				const Joint Shoulder;
				const Joint Elbow;
				const Joint Wrist;
				const Joint Hand;

				const Efficio::Models::Body::Hand GetHand();
			};
		}
	}
}
