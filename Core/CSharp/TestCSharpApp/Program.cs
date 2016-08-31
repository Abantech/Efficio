using Efficio.Net;
using System;

namespace TestCSharpApp
{
    class Program
    {
        static void Main(string[] args)
        {
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
                }
            }
        }
    }
}