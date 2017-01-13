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
		/// Continuous gestures are gestures that are done over time
		class DLLEXPORT ContinuousGesture : public Gesture
		{
		public:
			ContinuousGesture(std::string source);
			~ContinuousGesture();
			GestureType GetGestureType() override { return GestureType::Continuous; };
			virtual GestureState GetGestureState() = 0;
		};
	}
}