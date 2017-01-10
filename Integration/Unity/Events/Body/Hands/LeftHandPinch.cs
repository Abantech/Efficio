using System;
using Efficio.Unity.MessageBus;
using Efficio.Unity.MessageBus.Body.Hands;

namespace Efficio.Unity.Events.Body.Hands
{
    public abstract class LeftHandIndexMiddlePinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandIndexMiddlePinch }; }
        }
    }

    public abstract class LeftHandIndexPinkyPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandIndexPinkyPinch }; }
        }
    }

    public abstract class LeftHandIndexRingPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandIndexRingPinch }; }
        }
    }

    public abstract class LeftHandMiddlePinkyPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandMiddlePinkyPinch }; }
        }
    }

    public abstract class LeftHandMiddleRingPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandMiddleRingPinch }; }
        }
    }

    public abstract class LeftHandRingPinkyPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandRingPinkyPinch }; }
        }
    }

    public abstract class LeftHandThumbIndexPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandThumbIndexPinch }; }
        }
    }

    public abstract class LeftHandThumbMiddlePinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandThumbMiddlePinch }; }
        }
    }

    public abstract class LeftHandThumbPinkyPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandThumbPinkyPinch }; }
        }
    }

    public abstract class LeftHandThumbRingPinch : Pinch
    {
        protected override MessageType[] messageTypes
        {
            get { return new MessageType[] { MessageType.LeftHandThumbRingPinch }; }
        }
    }
}