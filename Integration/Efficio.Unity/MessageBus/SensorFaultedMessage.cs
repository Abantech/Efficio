using Efficio.Net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.MessageBus
{
    public class SensorFaultedMesssage : Message
    {
        public SensorFaultedMesssage(Faulted faultedEvent)
        {
            this.Type = MessageType.SensorFaulted;
        }
    }
}