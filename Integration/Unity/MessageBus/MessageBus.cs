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

        public void SendMessage(Message message)
        {
            if (!subscriberLists.ContainsKey(message.Type))
            {
                Debug.Log("MESSAGE BUS: Message of type " + message.Type + " received but no message handlers registered.");
                return;
            }

            var subscriberList = subscriberLists[message.Type];

            for (int i = 0; i < subscriberList.Count; i++)
            {
                Debug.Log(string.Format("MESSAGE BUS: Message of type {0} received. This message type has {1} handlers registered.", message.Type, subscriberList.Count));
                SendMessageToSubscriber(message, subscriberList[i]);
                //Action<Message, MessageSubscriber> sendMessage = SendMessageToSubscriber;
                //sendMessage.BeginInvoke(message, subscriberList[i], null, null);
            }
        }

        void SendMessageToSubscriber(Message message, MessageSubscriber subscriber)
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
