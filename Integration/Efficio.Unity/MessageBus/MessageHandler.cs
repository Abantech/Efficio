using UnityEngine;

namespace Efficio.Unity.MessageBus
{
    public abstract class MessageHandler : MonoBehaviour
    {
        public abstract MessageType[] MessageTypes { get; }
        public abstract void HandleMessage(Message message);

        void Start()
        {
            MessageSubscriber subscriber = new MessageSubscriber();
            subscriber.MessageTypes = MessageTypes;
            subscriber.Handler = this;

            MessageBus.Instance.AddSubscriber(subscriber);
        }
    }
}