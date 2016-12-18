using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Efficio.Unity.MessageBus
{
    public class MessageBus
    {
        Dictionary<MessageType, List<MessageSubscriber>> subscriberLists = new Dictionary<MessageType, List<MessageSubscriber>>();

        public void AddSubscriber(MessageSubscriber subscriber)
        {
            MessageType[] messageTypes = subscriber.MessageTypes;
            for (int i = 0; i < messageTypes.Length; i++)
                AddSubscriberToMessage(messageTypes[i], subscriber);
        }

        void AddSubscriberToMessage(MessageType messageType,
                             MessageSubscriber subscriber)
        {
            if (!subscriberLists.ContainsKey(messageType))
            {
                subscriberLists[messageType] = new List<MessageSubscriber>();
            }

            subscriberLists[messageType].Add(subscriber);
        }

        public void SendMessage(IMessage message)
        {
            if (!subscriberLists.ContainsKey(message.GetMessageType))
            {
                return;
            }

            var subscriberList = subscriberLists[message.GetMessageType];

            for (int i = 0; i < subscriberList.Count; i++)
            {
                SendMessageToSubscriber(message, subscriberList[i]);
                //Action<Message, MessageSubscriber> sendMessage = SendMessageToSubscriber;
                //sendMessage.BeginInvoke(message, subscriberList[i], null, null);
            }
        }

        void SendMessageToSubscriber(IMessage message, MessageSubscriber subscriber)
        {
            subscriber.Handler.HandleMessage(message);
        }

        static MessageBus instance;

        public static MessageBus Instance
        {
            get
            {
                if (instance == null)
                    instance = new MessageBus();

                return instance;
            }
        }

        private MessageBus() { }
    }
}
