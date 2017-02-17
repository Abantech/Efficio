using Efficio.Unity.Events.Body.Hands;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Efficio.Unity.MessageBus.Body.Hands;

namespace Efficio.Unity
{
    class GregsUnityScript : RightHandIndexMiddlePinch
    {
        public override void HandlePinch(PinchMessage message)
        {
            this.transform.position = new UnityEngine.Vector3(message.Position.x, message.Position.y, message.Position.z);
        }
    }
}
