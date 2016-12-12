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
                            var pinch = SWIGHelper.CastTo<Pinch>(ev, false);
                            if (pinch != null)
                            {
                                PinchMessage pinchMessage = new PinchMessage(pinch);

                                MessageBus.MessageBus.Instance.SendMessage(pinchMessage);
                            }
                            break;
                        case Net.EventType.EfficioStarted:
                            var started = SWIGHelper.CastTo<EfficioStarted>(ev, false);
                            if (started != null)
                            {
                                //EfficioStartedMessage startedMessage = new EfficioStartedMessage(started);

                               // MessageBus.MessageBus.Instance.SendMessage(startedMessage);
                            }
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