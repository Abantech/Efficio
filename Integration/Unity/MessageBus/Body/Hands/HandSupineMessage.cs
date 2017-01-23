using Efficio.Net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.MessageBus.Body.Hands
{
    public class HandSupineMessage : Message
    {
        public HandSupineMessage(BodySide side, MessageType type)
        {
            this.Side = side;
            this.Type = type;
        }

        public HandSupineMessage(HandSupine supine) 
            : this(supine.Side, (MessageType)Enum.Parse(typeof(MessageType), supine.Side.ToString() + "HandSupine"))
        {
        }

        public BodySide Side { get; }
    }
}