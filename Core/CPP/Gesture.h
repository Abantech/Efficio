#pragma once
#include <ctime>
#include "Enumerations.h"
#include "Event.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio {
	namespace InputRecognition
	{
		/// Base class for all gestures that may occur within the Efficio system.
		extern class DLLEXPORT Gesture : public Event
		{
		public:
			Gesture();
			~Gesture();

			/// Gets the type of gesture that is occurring.
			virtual GestureType GetType() = 0;

			/// Gets the state of the gesture.
			virtual GestureState GetGestureState() = 0;

			/// Gets the start time of the gesture
			const std::time_t GetStartTime();

			/// Getst the length of the gesture.
			const std::time_t GetGestureDuration();

			virtual void Eh() = 0;
		protected:
			void Detected();

		private:
			std::time_t startTime;
		};
	}
}