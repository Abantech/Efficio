using Efficio.Unity.MessageBus;
using Efficio.Unity.MessageBus.Body.Hands;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.Events.Body.Hands
{
    public abstract class Supine : MessageHandler
    {
        public override MessageType[] MessageTypes
        {
            get
            {
                return new MessageType[] {
                    MessageType.RightHandSupine,
                    MessageType.LeftHandSupine
                };
            }
        }

        public override void HandleMessage(Message message)
        {
            this.HandleHandSupine((HandSupineMessage)message);
        }

        public abstract void HandleHandSupine(HandSupineMessage message);
    }

    public abstract class RightHandSupine : Supine
    {
        public override MessageType[] MessageTypes
        {
            get { return new MessageType[] { MessageType.RightHandSupine }; }
        }
    }

    public abstract class LeftHandSupine : Supine
    {
        public override MessageType[] MessageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandSupine }; }
        }
    }
}
