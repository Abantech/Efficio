using Efficio.Unity.Events.Body.Hands;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Efficio.Unity.MessageBus.Body.Hands;
using UnityEngine;

namespace Efficio.Unity
{
    public class GregsUnityScript : LeftHandIndexMiddlePinch
    {
        public override void HandlePinch(PinchMessage message)
        {
            this.transform.position = new UnityEngine.Vector3(message.Position.x, message.Position.y, message.Position.z);
            this.GetComponent<Rigidbody>().useGravity = !this.GetComponent<Rigidbody>().useGravity;
        }
    }
}
