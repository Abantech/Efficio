using Efficio.Net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.MessageBus
{
    public class SensorConnectedMesssage : ISensorUpdatedMessage
    {
        public SensorConnectedMesssage(Connected connectedEvent)
        {
        }

        public MessageType GetMessageType
        {
            get
            {
                return MessageType.SensorConnected;
            }
        }
    }
}