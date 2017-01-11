#include "Event.h"

namespace Efficio 
{
	namespace Events
	{
		size_t Event::IdIndex = 0;

		Event::Event() : Time(NULL)
		{
			ID = IdIndex++;
		}

		Event::~Event()
		{
		}
	}
}