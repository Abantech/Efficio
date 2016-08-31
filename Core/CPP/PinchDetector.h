#pragma once

#include "SingleHandGestureDetector.h"
#include "Pinch.h"

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
			namespace Hands
			{
				extern class DLLEXPORT PinchDetector : public SingleHandGestureDetector
				{
				public:
					std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>> Detect(Leap::Hand hand);
					bool Enabled;
				};
			}
		}
	}
}