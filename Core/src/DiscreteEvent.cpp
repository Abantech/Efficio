#include "DiscreteEvent.h"

namespace Efficio {
	DiscreteEvent::DiscreteEvent(std::string soruce) : Event(soruce), Time(NULL) { }
	DiscreteEvent::~DiscreteEvent() { }
}