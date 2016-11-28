using UnityEngine;
using System.Collections;
using Efficio.Unity.Events.Body.Hands;
using Efficio.Unity.MessageBus.Body.Hands;
using System;

public class CreateSpheres : RightHandThumbIndexPinch
{
    private static DateTime last;
    public override void HandlePinch(PinchMessage message)
    {
        if (DateTime.Now - last < new TimeSpan(0, 0, 0, 0, 200))
        {
            return;
        }

        last = DateTime.Now;
        var obj = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        obj.transform.position = transform.TransformPoint(new Vector3(0.0f, 0.0f - 0.3f, 0.0f));
        var rb = obj.AddComponent<Rigidbody>();
        rb.velocity = new Vector3(-10, 0, 10);
    }
}
