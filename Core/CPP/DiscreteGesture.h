#pragma once
#include "Gesture.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio 
{
	namespace InputRecognition
	{
		/// Discrete gestures are gestures that are always in a completed state.
		extern class DLLEXPORT DiscreteGesture : public Gesture
		{
		public:
			DiscreteGesture();
			~DiscreteGesture();
			GestureType GetType() { return GestureType::Discrete; };
			GestureState GetGestureState() { return GestureState::Completed; };
		};
	}
}