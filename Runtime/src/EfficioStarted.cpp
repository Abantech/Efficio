#include "EfficioStarted.h"

namespace Efficio
{
	EfficioStarted::EfficioStarted() : DiscreteEvent("Efficio Engine") { }
	EfficioStarted::~EfficioStarted() { }

	std::string EfficioStarted::GetEventType() { return EfficioStarted::EventType; }

	const std::string EfficioStarted::EventType = "EfficioStarted";
}