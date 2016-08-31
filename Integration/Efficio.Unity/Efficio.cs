using UnityEngine;
using Efficio.Unity.MessageBus.Body.Hands;
using Efficio.Net;

namespace Efficio.Unity
{
    public class Efficio : MonoBehaviour
    {
        private Engine engine;

        void Start()
        {
            engine = new Engine();

            engine.DeviceConfiguration.LeapConfiguration.Enabled = true;

            engine.Start();
        }

        void Update()
        {
            var frame = engine.GetFrame();

            if (frame.GetEvents().Count > 0)
            {
                foreach (var ev in frame.GetEvents())
                {
                    switch (ev.GetEventType())
                    {
                        case Net.EventType.Pinch:
                            if (SWIGHelper.CastTo<Pinch>(ev, false) != null)
                            {
                                var pinch = SWIGHelper.CastTo<Pinch>(ev, false);

                                PinchMessage pinchMessage = new PinchMessage(pinch);

                                MessageBus.MessageBus.Instance.SendMessage(pinchMessage);
                            }
                            break;
                        case Net.EventType.EfficioStarted:
                            break;
                        default:
                            break;
                    }
                }
            }
        }

        void OnDestroy()
        {
            engine.Dispose();
        }
    }
}