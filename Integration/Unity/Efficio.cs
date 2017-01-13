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
                                EfficioStartedMessage startedMessage = new EfficioStartedMessage(started);

                                MessageBus.MessageBus.Instance.SendMessage(startedMessage);
                            }
                            break;
                        case Net.EventType.ButtonPressed:
                            {
                                var buttonPressed = SWIGHelper.CastTo<ButtonPressed>(ev, false);
                                if (buttonPressed != null)
                                {
                                    ButtonPressedMessage buttonPressedMessage = new ButtonPressedMessage(buttonPressed);
                                    MessageBus.MessageBus.Instance.SendMessage(buttonPressedMessage);
                                }

                                break;
                            }
                        case Net.EventType.SensorConnected:
                            {
                                var sensorConnected = SWIGHelper.CastTo<Connected>(ev, false);
                                if (sensorConnected != null)
                                {
                                    SensorConnectedMesssage sensorConnectedMesssage = new SensorConnectedMesssage(sensorConnected);
                                    MessageBus.MessageBus.Instance.SendMessage(sensorConnectedMesssage);
                                }
                                break;
                            }
                        case Net.EventType.SensorFaulted:
                            {
                                var sensorFaulted = SWIGHelper.CastTo<Faulted>(ev, false);
                                if (sensorFaulted != null)
                                {
                                    SensorFaultedMesssage sensorFaultedMesssage = new SensorFaultedMesssage(sensorFaulted);
                                    MessageBus.MessageBus.Instance.SendMessage(sensorFaultedMesssage);
                                }
                                break;
                            }
                        case Net.EventType.SensorDisconnected:
                            {
                                var sensorDisconnected = SWIGHelper.CastTo<Disconnected>(ev, false);
                                if (sensorDisconnected != null)
                                {
                                    SensorDisconnectedMesssage sensorDisconnectedMesssage = new SensorDisconnectedMesssage(sensorDisconnected);
                                    MessageBus.MessageBus.Instance.SendMessage(sensorDisconnectedMesssage);
                                }
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