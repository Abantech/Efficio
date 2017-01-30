using System.Linq;

namespace Efficio.Net.Experimentation
{
    class Program
    {
        static void Main(string[] args)
        {
            var engine = new Engine();

            var startFrame = engine.Start();

            foreach (var ev in startFrame.GetEvents())
            {
                switch (ev.GetEventType())
                {
                    case EventType.EfficioStarted:
                        var e = SWIGHelper.CastTo<EfficioStarted>(ev, false);
                        break;
                    case EventType.SensorConnecting:
                        break;
                    case EventType.SensorConnected:
                        break;
                    case EventType.SensorDisconnecting:
                        break;
                    case EventType.SensorDisconnected:
                        break;
                    case EventType.SensorFaulted:
                        break;
                    case EventType.Pinch:
                        break;
                    default:
                        break;
                }

            }

            while (true)
            {
                var frame = engine.GetFrame();

                if (frame.GetEvents().Count > 0)
                {
                    var ev = frame.GetEvents()[0];

                    if (ev.GetEventType() == EventType.Pinch)
                    {
                        var pinch = SWIGHelper.CastTo<Pinch>(ev);
                        var finger = pinch.Finger1;

                        var handData = frame.GetDataOfType<HandData>();

                        if (handData.Count() > 0)
                        {
                            var hand = handData.ElementAt(0).Hands.First(x => x.ID == pinch.HandID);
                        }
                    }
                }
            }
        }
    }
}