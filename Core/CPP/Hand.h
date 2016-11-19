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
				Hand(BodySide side, array<Finger, 5> fingers);
				~Hand();

				/// The side of the body
				const BodySide Side;

				/// The fingers of the hand
				const array<Finger, 5> Fingers;


			};
		}
	}
}