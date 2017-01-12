using Efficio.Unity.MessageBus;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.Events
{
    public abstract class EfficioStartedHandler : MessageHandler
    {
        public override MessageType[] MessageTypes
        {
            get
            {
                return new MessageType[] { MessageType.EfficioStarted };
            }
        }

        public override void HandleMessage(Message message)
        {
            this.HandleEfficioStarted((EfficioStartedMessage)message);
        }

        public abstract void HandleEfficioStarted(EfficioStartedMessage message);
    }
}
