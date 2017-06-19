#pragma once

#include "DiscreteEvent.h"

namespace Efficio
{
	/// An event indicating that Efficio has started
	class EfficioStarted : public Efficio::DiscreteEvent
	{
	public:
		EfficioStarted();
		~EfficioStarted();

		/// Gets the event type
		virtual std::string GetEventType();

		static const std::string EventType;
	};
}