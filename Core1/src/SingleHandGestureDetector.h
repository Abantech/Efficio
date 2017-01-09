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
					virtual std::vector<std::shared_ptr<InputRecognition::Gesture>> Detect(Models::Body::Hand hand) = 0;
				};
			}
		}
	}
}