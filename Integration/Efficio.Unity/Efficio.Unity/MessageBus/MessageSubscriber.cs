﻿namespace Efficio.Unity.MessageBus
{
    public struct MessageSubscriber
    {
        public MessageType[] MessageTypes;
        public MessageHandler Handler;
    }
}
