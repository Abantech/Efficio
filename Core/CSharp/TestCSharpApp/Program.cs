using Efficio.Net;
using System;

namespace TestCSharpApp
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime disabledTime = DateTime.Now;

            var engine = new Engine();
            engine.DeviceConfiguration.LeapConfiguration.Enabled = true;

            engine.Start();
            DateTime startTime = DateTime.Now;

            while (true)
            {
                var frame = engine.GetFrame();

                if (frame.GetEvents().Count > 0)
                {
                    var ev = SWIGHelper.CastTo<Pinch>(frame.GetEvents()[0], false);
                    
                    int i = 0;

                    DisableAllDevices(engine.DeviceManager);
                    disabledTime = DateTime.Now;
                }

                if (frame.GetHands().Count > 0)
                {
                    foreach(var hand in frame.GetHands())
                    {
                        var messageBuilder = new System.Text.StringBuilder();
                        var currentHand = SWIGHelper.CastTo<Hand>(hand, false);

                        //var fingerCollection = SWIGHelper.CastTo<Finger[]>(currentHand.Fingers, false) // HELP!!!! THIS DOES NOT WORK
                        //currentHand.GetFingers()
                        //var currentFinger = new Finger();

                        //foreach(var currentFinger in )
                        //{
                        //    var c

                        //}
                        messageBuilder.AppendFormat("Detected {0} Hand!!!", currentHand.Side.ToString());
                        Console.Out.WriteLine(messageBuilder.ToString());
                    }
                }

                // Disabled devices for 3 seconds when pinch detected
                if ((DateTime.Now - disabledTime).Seconds > 3)
                {
                    EnableAllDevices(engine.DeviceManager);
                }
            }
        }

        private static void DisableAllDevices(DeviceManager manager)
        {
            var devices = manager.GetDevicesWithStatus(DeviceStatus.Connected);

            foreach (var device in devices)
            {
                device.Enabled = false;
            }
        }

        private static void EnableAllDevices(DeviceManager manager)
        {
            foreach (var device in manager.GetDevices())
            {
                device.Enabled = true;
            }
        }
    }
}