#include "Event.h"

namespace Efficio
{
	size_t Event::IdIndex = 0;

	Event::Event(std::string source) : Source(source) { ID = IdIndex++; }
	Event::~Event() { }
}