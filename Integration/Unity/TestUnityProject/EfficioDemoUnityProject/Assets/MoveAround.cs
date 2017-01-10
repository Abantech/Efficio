using Efficio.Unity.Events.Body.Hands;
using Efficio.Unity.MessageBus.Body.Hands;

public class MoveAround : RightHandThumbIndexPinch
{
    public int Multiplier;

    public override void HandlePinch(PinchMessage message)
    {
        var temp = transform.position;
        temp.x = message.Position.X() * Multiplier;
        temp.y = message.Position.Y() * Multiplier;
        temp.z = -message.Position.Z() * Multiplier;
        transform.position = temp;
    }
}
