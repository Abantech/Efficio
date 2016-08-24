using UnityEngine;
using Efficio.Runtime;
using Efficio.Unity.MessageBus.Body.Hands;

namespace Efficio.Unity
{
    public class Efficio : MonoBehaviour
    {
        private Engine engine;

        // Use this for initialization
        void Start()
        {
            engine = new Engine();

            LeapConfiguration leapConfig = new LeapConfiguration();
            leapConfig.Enabled = true;

            DeviceConfiguration config = new DeviceConfiguration();
            config.SetLeapConfiguration(leapConfig);
            engine.DeviceConfiguration = config;

            engine.Start();
        }

        // Update is called once per frame
        void Update()
        {
            var frame = engine.GetFrame();

            if (frame.GetEvents().Count > 0)
            {
                foreach (var ev in frame.GetEvents())
                {
                    if (SWIGHelper.CastTo<PinchEvent>(ev, false) != null)
                    {
                        var pinch = SWIGHelper.CastTo<PinchEvent>(ev, false);

                        PinchMessage pinchMessage = new PinchMessage();

                        pinchMessage.Side = pinch.Side() == BodySide.Left ? Side.Left : Side.Right;
                        pinchMessage.Position = new UnityEngine.Vector3(pinch.Position().X(), pinch.Position().Y(), pinch.Position().Z());

                        MessageBus.MessageBus.Instance.SendMessage(pinchMessage);
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