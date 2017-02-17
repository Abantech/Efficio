using System;
using Efficio.Unity.MessageBus;
using Efficio.Unity.MessageBus.Body.Hands;

namespace Efficio.Unity.Events.Body.Hands
{
    public abstract class RightHandIndexMiddlePinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.RightHandIndexMiddlePinch }; }
        }
    }

    public abstract class RightHandIndexPinkyPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.RightHandIndexPinkyPinch }; }
        }
    }

    public abstract class RightHandIndexRingPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.RightHandIndexRingPinch }; }
        }
    }

    public abstract class RightHandMiddlePinkyPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.RightHandMiddlePinkyPinch }; }
        }
    }

    public abstract class RightHandMiddleRingPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.RightHandMiddleRingPinch }; }
        }
    }

    public abstract class RightHandRingPinkyPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.RightHandRingPinkyPinch }; }
        }
    }

    public abstract class RightHandThumbIndexPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.RightHandThumbIndexPinch }; }
        }
    }

    public abstract class RightHandThumbMiddlePinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.RightHandThumbMiddlePinch }; }
        }
    }

    public abstract class RightHandThumbPinkyPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.RightHandThumbPinkyPinch }; }
        }
    }

    public abstract class RightHandThumbRingPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.RightHandThumbRingPinch }; }
        }
    }
}