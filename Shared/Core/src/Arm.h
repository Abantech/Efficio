#pragma once

#include "BodySide.h"
#include "Joint.h"
#include "Hand.h"

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
			/// Representation of a human arm
			class DLLEXPORT Arm
			{
			public:
				Arm(Joint shoulder, Joint elbow, Joint wrist, Joint hand);
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
