#pragma once
#include "Event.h"
#include <string>
#include <memory>

namespace Efficio
{
	class Message
	{
	public:
		Message(const std::string eventType, std::shared_ptr<Event> ev);
		~Message();
		std::string GetEventType();

		std::shared_ptr<Event> GetEvent();
	private:
		std::shared_ptr<Event> messageEvent;
		std::string evType;
	};
}