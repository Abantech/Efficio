using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Efficio.Net;

namespace Efficio.Unity.MessageBus
{
    public class EfficioStartedMessage : Message
    {
        EfficioStarted startedEvent;

        public EfficioStartedMessage(EfficioStarted startedEvent)
        {
            this.Type = MessageType.EfficioStarted;
            this.startedEvent = startedEvent;
        }
    }
}
