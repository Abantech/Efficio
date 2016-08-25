#pragma once

#include "DiscreteGesture.h"
#include "Leap.h"
#include "Enumerations.h"
#include "Vector3.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hand {
				/// A gesture that occurs when two finger tips are touching.
				class Pinch : public DiscreteGesture
				{
				public:
					Pinch(Efficio::Body::BodySide side, Vector3 position);
					~Pinch();

					/// The side of the body on which the pinch occurred
					Efficio::Body::BodySide Side;

					/// The finger involved in the pinch.
					Efficio::Body::Finger Finger1;

					/// The other finger involved in the pinch.
					Efficio::Body::Finger Finger2;

					/// The ID of the hand
					std::string ID;

					/// The location of the pinch
					Efficio::Vector3 Position;

					/// Detects whether or not the hand is pinching
					static bool Detect(Leap::Hand hand);

					virtual void Eh() {};
				private:

				};
			}
		}
	}
}