using Efficio.Net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.MessageBus
{
    public class SensorConnectedMesssage : Message
    {
        public SensorConnectedMesssage(Connected connectedEvent)
        {
            this.Type = MessageType.SensorConnected;
        }
    }
}