#pragma once

#include "SingleHandGestureDetector.h"

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
				extern class DLLEXPORT PinchDetector : public SingleHandGestureDetector
				{
				public:
					PinchDetector();
					~PinchDetector();

					// Inherited via SingleHandGestureDetector
					virtual std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>> Detect(Models::Body::Hand hand) override;
				};
			}
		}
	}
}