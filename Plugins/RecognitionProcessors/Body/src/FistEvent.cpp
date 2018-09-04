#include "..\include\FistEvent.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			FistEvent::FistEvent(std::string source, Models::Body::BodySide side) : DiscreteEvent(source), Side(side) { }
			FistEvent::~FistEvent() { }

			std::string FistEvent::GetEventType() { return FistEvent::EventType; }

			const std::string FistEvent::EventType = "Fist";
		}
	}
}