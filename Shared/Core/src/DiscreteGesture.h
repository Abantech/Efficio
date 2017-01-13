#pragma once
#include "Gesture.h"

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
		/// Discrete gestures are gestures that are always in a completed state.
		class DLLEXPORT DiscreteGesture : public Gesture
		{
		public:
			DiscreteGesture();
			~DiscreteGesture();
			GestureType GetGestureType() override { return GestureType::Discrete; };
			GestureState GetGestureState() override { return GestureState::Completed; };
		};
	}
}