#pragma once

#include "Leap.h"
#include <vector>
#include <memory>
#include "Gesture.h"
#include <array>
#include "Finger.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
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
					std::array<Efficio::Body::FingerType, 5> FingerNames = 
					{ 
						Efficio::Body::FingerType::Thumb,
						Efficio::Body::FingerType::Index,
						Efficio::Body::FingerType::Middle,
						Efficio::Body::FingerType::Ring,
						Efficio::Body::FingerType::Pinky
					};
				};
			}
		}
	}
}