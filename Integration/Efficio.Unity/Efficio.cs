using UnityEngine;
using Efficio.Unity.MessageBus.Body.Hands;
using Efficio.Net;
using Efficio.Unity.MessageBus;

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
                        case Net.EventType.ButtonPressed:
                            {
                                var buttonPressed = SWIGHelper.CastTo<GearVRAction>(ev, false);
                                if (buttonPressed != null)
                                {
                                    ButtonPressedMessage buttonPressedMessage = new ButtonPressedMessage(buttonPressed);
                                    MessageBus.MessageBus.Instance.SendMessage(buttonPressedMessage);
                                }

                                break;
                            }
                        case Net.EventType.SensorConnected:
                            {
                                //var sensorConnected = SWIGHelper.CastTo<Sen>
                                break;
                            }
                        case Net.EventType.SensorFaulted:
                            {

                                break;
                            }
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