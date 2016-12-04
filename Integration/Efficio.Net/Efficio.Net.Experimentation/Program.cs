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

                if (frame.GetEvents().Count > 0)
                {
                    var ev = frame.GetEvents()[0];
                }
            }
        }
    }
}