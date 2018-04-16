#pragma once

#include <functional>
#include <queue>
#include <map>
#include <vector>
#include "Message.h"

namespace Efficio
{
	class MessageBus
	{
		friend class Engine;
	public:
		~MessageBus() {}

		void AddReceiver(std::string messageType, std::function<void(Message)> messageReceiver);
		void SendMessage(Message message);

		static std::shared_ptr<MessageBus> Current();
	private:
		std::map<std::string, std::vector<std::function<void(Message)>>> receivers;
		std::queue<Message> messages;
		MessageBus() {};
		void Notify();
		void ClearMessages();
		MessageBus(MessageBus const&) = delete;
		void operator=(MessageBus const&) = delete;
	};
}