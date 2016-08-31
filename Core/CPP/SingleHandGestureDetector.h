#pragma once

#include "Leap.h"
#include <vector>
#include <memory>
#include "Gesture.h"
#include <array>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#endif

namespace Efficio {
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hands
			{
				extern class DLLEXPORT SingleHandGestureDetector {
				public:
					virtual std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>> Detect(Leap::Hand hand) = 0;
				protected:
					std::array<Body::Finger, 5> FingerNames = { Body::Finger::Thumb, Body::Finger::Index, Body::Finger::Middle, Body::Finger::Ring, Body::Finger::Pinky };
				};
			}
		}
	}
}