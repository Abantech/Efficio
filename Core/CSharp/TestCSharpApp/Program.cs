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

            engine.Start();

            while (true)
            {
                var frame = engine.GetFrame();

                if (frame.GetEvents().Count > 0)
                {
                    foreach (var ev in frame.GetEvents())
                    {
                        var pinch = SWIGHelper.CastTo<Pinch>(ev, false);

                        Console.WriteLine($"{pinch.Side} hand {pinch.Finger1.FingerType} and {pinch.Finger2.FingerType}");
                    }
                }
            }
        }
    }
}