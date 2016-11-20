#include "Gesture.h"

//UML: TBD

namespace Efficio {

	namespace InputRecognition {
		Gesture::Gesture()
		{
		}

		Gesture::~Gesture()
		{
		}

		const std::time_t Gesture::GetStartTime()
		{
			return startTime;
		}

		const std::time_t Gesture::GetGestureDuration()
		{
			return difftime(time(NULL), startTime);
		}
	}
}