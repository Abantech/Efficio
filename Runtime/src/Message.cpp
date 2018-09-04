#include "Message.h"

namespace Efficio
{
	Message::Message(const std::string eventType, std::shared_ptr<Event> ev) : evType(eventType), messageEvent(ev) { }
	Message::~Message() {}

	std::shared_ptr<Event> Message::GetEvent() { return messageEvent; }
	std::string Message::GetEventType() { return evType; }
}