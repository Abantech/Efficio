using System;
using UnityEngine;

namespace Efficio.Unity.MessageBus.Body.Hands
{
    public class PinchMessage : Message
    {
        public Side Side { get; set; }

        public string Finger1 { get; set; }

        public string Finger2 { get; set; }

        public Vector3 Position { get; set; }
        
    }

    public enum Side
    {
        Left,
        Right
    }
}
