using Efficio.Unity.MessageBus;
using Efficio.Unity.MessageBus.Body.Hands;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.Events.Body.Hands
{
    public abstract class Pinch : MessageHandler
    {
        protected virtual MessageType[] messageTypes
        {
            get
            {
                return new MessageType[] {
                    MessageType.LeftHandIndexMiddlePinch,
                    MessageType.LeftHandIndexPinkyPinch,
                    MessageType.LeftHandIndexRingPinch,
                    MessageType.LeftHandMiddlePinkyPinch,
                    MessageType.LeftHandMiddleRingPinch,
                    MessageType.LeftHandRingPinkyPinch,
                    MessageType.LeftHandThumbIndexPinch,
                    MessageType.LeftHandThumbMiddlePinch,
                    MessageType.LeftHandThumbPinkyPinch,
                    MessageType.LeftHandThumbRingPinch,
                    MessageType.RightHandIndexMiddlePinch,
                    MessageType.RightHandIndexPinkyPinch,
                    MessageType.RightHandIndexRingPinch,
                    MessageType.RightHandMiddlePinkyPinch,
                    MessageType.RightHandMiddleRingPinch,
                    MessageType.RightHandRingPinkyPinch,
                    MessageType.RightHandThumbIndexPinch,
                    MessageType.RightHandThumbMiddlePinch,
                    MessageType.RightHandThumbPinkyPinch,
                    MessageType.RightHandThumbRingPinch,
                };
            }
        }

        public override MessageType[] MessageTypes
        {
            get
            {
                return messageTypes;
            }
        }

        public abstract void HandlePinch(PinchMessage message);

        public override void HandleMessage(Message message)
        {
            HandlePinch((PinchMessage)message);
        }
    }
}
