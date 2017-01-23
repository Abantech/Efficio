#pragma once

#include "SingleHandGestureDetector.h"

#if WINDOWS
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
#define DLLEXPORT
#endif

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Body
		{
			namespace Hands
			{
				class DLLEXPORT SupineDetector : public SingleHandGestureDetector
				{
				public:
					SupineDetector();
					~SupineDetector();

					// Inherited via SingleHandGestureDetector
					virtual std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>> Detect(Models::Body::Hand hand) override;
				};
			}
		}
	}
}