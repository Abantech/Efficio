using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace Efficio.Net.Web
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in code, svc and config file together.
    // NOTE: In order to launch WCF Test Client for testing this service, please select Service1.svc or Service1.svc.cs at the Solution Explorer and start debugging.
    public class EfficioService : IEFficioService
    {
        private static Engine engine;

        public Engine Engine
        {
            get
            {
                if (engine == null)
                {
                    engine = new Engine();
                    engine.Start();
                }

                return engine;
            }
        }
        public Frame GetFrame()
        {
            var frame = this.Engine.GetFrame();

            //try
            //{
            //    while (frame.GetEvents().Count < 1)
            //    {
            //        frame = this.Engine.GetFrame();
            //    }
            //}
            //catch (Exception e)
            //{

            //    throw;
            //}

            return frame;
        }
    }
}
