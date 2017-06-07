#include "DiscreteEvent.h"

namespace Efficio {
	DiscreteEvent::DiscreteEvent(std::string name) : Event(name), Time(NULL) {}

	DiscreteEvent::~DiscreteEvent() {}

	std::string DiscreteEvent::GetEventType() 
	{
		return "Discrete";
	}
}