#include "MessageBus.h"

namespace Efficio
{
	void MessageBus::AddReceiver(std::string messageType, std::function<void(Message)> messageReceiver)
	{
		receivers[messageType].push_back(messageReceiver);
	}

	void MessageBus::SendMessage(Message message) { messages.push(message); }

	void MessageBus::Notify()
	{
		while (!messages.empty()) {
			auto eventType = messages.front().GetEventType();
			auto receiversForMessage = receivers[eventType];

			for (size_t i = 0; i < receiversForMessage.size(); i++)
			{
				(receiversForMessage[i])(messages.front());
			}

			messages.pop();
		}
	}

	void MessageBus::ClearMessages()
	{
		while (!messages.empty()) 
			messages.pop();
	}

	std::shared_ptr<MessageBus> MessageBus::Current()
	{
		static std::shared_ptr<MessageBus> instance = std::shared_ptr<MessageBus>(new MessageBus()); 
		return instance;
	}
}