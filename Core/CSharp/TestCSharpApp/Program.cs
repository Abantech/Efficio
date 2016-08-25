using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestCSharpApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var engine = new Efficio.Net.Engine();
            engine.DeviceConfiguration.LeapConfiguration.Enabled = true;

            engine.Start();

            while (true)
            {
                var frame = engine.GetFrame();

                foreach (var ev in frame.GetEvents())
                {
                    if (SWIGHelper.CastTo<Efficio.Net.Pinch>(ev, false) != null)
                    {
                        var pinch = SWIGHelper.CastTo<Efficio.Net.Pinch>(ev, false);
                        int i = 0;
                    }
                }
            }
        }
    }
}
