#pragma once
#include "Finger.h"
#include "Joint.h"
#include "BodySide.h"
#include <array>

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
			/// Representation of the human hand
			extern class DLLEXPORT Hand
			{

			public:
				Hand();
				~Hand();

				/// The joints of the hand excluding the joints of the fingers
				vector<shared_ptr<Joint>> Joints;

				/// The fingers of the hand
				array<shared_ptr<Finger>, 5> Fingers;

				/// The side of the body
				BodySide Side;
			};
		}
	}
}