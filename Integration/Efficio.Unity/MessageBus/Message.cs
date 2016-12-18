namespace Efficio.Unity.MessageBus
{
    public class Message : IMessage
    {
        protected MessageType Type;

        public MessageType GetMessageType
        {
            get
            {
                return this.Type;
            }
        }
    }
}
