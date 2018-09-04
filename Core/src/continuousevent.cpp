#include "ContinuousEvent.h"

namespace Efficio {
	ContinuousEvent::ContinuousEvent(std::string name) : Event(name), StartTime(NULL) { }

	ContinuousEvent::~ContinuousEvent() { }

	std::string ContinuousEvent::GetEventType() { return "Continuous"; }

	int ContinuousEvent::Duration() {
		//TODO calculate time difference
		return 0;
	}
}