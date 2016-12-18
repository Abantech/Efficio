using Efficio.Net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.MessageBus
{
    public class SensorDisconnectedMesssage : ISensorUpdatedMessage
    {
        public SensorDisconnectedMesssage(Disconnected disconnectedEvent)
        {
        }

        public MessageType GetMessageType
        {
            get
            {
               return MessageType.SensorDisconnected;
            }
        }
    }
}