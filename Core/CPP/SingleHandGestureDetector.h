#pragma once

#include "Leap.h"
#include <vector>
#include <memory>
#include "Gesture.h"
#include <array>
#include "Hand.h"

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
					virtual std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>> Detect(Efficio::Models::Human::Hand hand) = 0;
				};
			}
		}
	}
}