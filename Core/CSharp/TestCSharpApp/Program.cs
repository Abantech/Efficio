using System;

namespace TestCSharpApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var engine = new Efficio.Net.Engine();
            int pinchFrames = 0;
            engine.DeviceConfiguration.LeapConfiguration.Enabled = true;

            engine.Start();
            DateTime startTime = DateTime.Now;

            while (true)
            {
                var frame = engine.GetFrame();

                if (frame.GetEvents().Count > 0)
                {
                    pinchFrames++;
                }

                if (frame.ID == 50000)
                {
                    TimeSpan executionTime = DateTime.Now - startTime;

                    double fps = 50000 / executionTime.TotalSeconds;
                    int totalPinchFrames = pinchFrames;
                    int success = 1;
                }
            }
        }
    }
}
