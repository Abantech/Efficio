#include "EfficioStarted.h"

namespace Efficio
{
	EfficioStarted::EfficioStarted() : DiscreteEvent("EfficioStarted")
	{
	}
	EfficioStarted::~EfficioStarted()
	{
	}
	std::string EfficioStarted::GetEventType() {
		return "EfficioStarted";
	}
}