using Efficio.Net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.MessageBus
{
    public class SensorFaultedMesssage : ISensorUpdatedMessage
    {
        public SensorFaultedMesssage(Faulted faultedEvent)
        {
        }

        public MessageType GetMessageType
        {
            get
            {
                return MessageType.SensorFaulted;
            }
        }
    }
}