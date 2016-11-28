#pragma once

#include <vector>
#include <memory>
#include "Gesture.h"
#include <array>
#include "FingerType.h"
#include "Hand.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio 
{
	namespace InputRecognition
	{
		namespace Body
		{
			namespace Hands
			{
				extern class DLLEXPORT SingleHandGestureDetector {
				public:
					virtual std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>> Detect(Models::Body::Hand hand) = 0;
				//protected:
				//	std::array<Efficio::Models::Body::FingerType, 5> FingerNames = 
				//	{ 
				//		Efficio::Models::Body::FingerType::Thumb,
				//		Efficio::Models::Body::FingerType::Index,
				//		Efficio::Models::Body::FingerType::Middle,
				//		Efficio::Models::Body::FingerType::Ring,
				//		Efficio::Models::Body::FingerType::Pinky
				//	};
				};
			}
		}
	}
}