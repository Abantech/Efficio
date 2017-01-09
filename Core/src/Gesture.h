#pragma once

#include <ctime>
#include "Event.h"
#include "GestureType.h"
#include "GestureState.h"

#if _WINDLL
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
		/// Base class for all gestures that may occur within the Efficio system.
		extern class DLLEXPORT Gesture : public Efficio::Events::Event
		{
		public:
			Gesture();
			~Gesture();

			/// Gets the type of gesture that is occurring.
			virtual GestureType GetType() = 0;

			/// Gets the state of the gesture.
			virtual GestureState GetGestureState() = 0;

			/// Gets the start time of the gesture
			std::time_t GetStartTime();

			/// Getst the length of the gesture.
			std::time_t GetGestureDuration();

			virtual Efficio::Events::EventType GetEventType() = 0;
		private:
			std::time_t startTime;
		};
	}
}