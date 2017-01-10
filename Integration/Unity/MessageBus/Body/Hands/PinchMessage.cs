using Efficio.Net;

namespace Efficio.Unity.MessageBus.Body.Hands
{
    public class PinchMessage : Message
    {
        public PinchMessage(Vector3 position, BodySide side, Finger finger1, Finger finger2, MessageType type)
        {
            this.Side = side;
            this.Finger1 = finger1;
            this.Finger2 = finger2;
            this.Position = position;
            this.Type = type;
        }

        public PinchMessage(Pinch pinch) : this(pinch.Position, pinch.Side, pinch.Finger1, pinch.Finger2, (MessageType)System.Enum.Parse(typeof(MessageType), pinch.Side.ToString() + "Hand" + pinch.Finger1.FingerType.ToString() + pinch.Finger2.FingerType.ToString() + "Pinch"))
        {
        }

        public BodySide Side { get; }

        public Finger Finger1 { get; }

        public Finger Finger2 { get; }

        public Vector3 Position { get; }
    }
}