using Efficio.Net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.MessageBus
{
    public class SensorDisconnectedMesssage : Message
    {
        public SensorDisconnectedMesssage(Disconnected disconnectedEvent)
        {
            this.Type = MessageType.SensorDisconnected;
        }
    }
}