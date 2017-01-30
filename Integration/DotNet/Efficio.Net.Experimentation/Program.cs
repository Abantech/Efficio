using System;
using System.Linq;

namespace Efficio.Net.Experimentation
{
    class Program
    {
        static void Main(string[] args)
        {
            var engine = new Engine();

            var startFrame = engine.Start();
            HandleEvents(startFrame);

            while (true)
            {
                var frame = engine.GetFrame();
                HandleEvents(frame);
            }
        }

        private static void HandleEvents(Frame frame)
        {
            foreach (var ev in frame.GetEvents())
            {
                switch (ev.GetEventType())
                {
                    case EventType.EfficioStarted:
                        Console.WriteLine("Efficio Started");
                        break;
                    case EventType.SensorConnecting:
                        var connecting = SWIGHelper.CastTo<Connecting>(ev);
                        Console.WriteLine(connecting.SensorInformation.Name + " Connecting");
                        break;
                    case EventType.SensorConnected:
                        var connected = SWIGHelper.CastTo<Connected>(ev);
                        Console.WriteLine(connected.SensorInformation.Name + " Connected");
                        break;
                    case EventType.SensorDisconnecting:
                        var disconnecting = SWIGHelper.CastTo<Disconnecting>(ev);
                        Console.WriteLine(disconnecting.SensorInformation.Name + " Disconnecting");
                        break;
                    case EventType.SensorDisconnected:
                        var disconnected = SWIGHelper.CastTo<Disconnected>(ev);
                        Console.WriteLine(disconnected.SensorInformation.Name + " Disconnected");
                        break;
                    case EventType.SensorFaulted:
                        var faulted = SWIGHelper.CastTo<Faulted>(ev);
                        Console.WriteLine(faulted.SensorInformation.Name + " Faulted");
                        break;
                    case EventType.Pinch:
                        var pinch = SWIGHelper.CastTo<Pinch>(ev);
                        var finger = pinch.Finger1;

                        var handData = frame.GetDataOfType<HandData>();

                        if (handData.Count() > 0)
                        {
                            var hand = handData.SelectMany(x => x.Hands).First(x => x.ID == (pinch.HandID));
                            Console.WriteLine("Pinch detected by " + hand.Source + " at frame " + frame.ID);
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
}