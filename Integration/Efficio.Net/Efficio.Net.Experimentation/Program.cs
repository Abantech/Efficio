using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Efficio.Net.Experimentation
{
    class Program
    {
        static void Main(string[] args)
        {
            var engine = new Engine();

            var startFrame = engine.Start();

            while (true)
            {
                var frame = engine.GetFrame();
            }
        }
    }
}
