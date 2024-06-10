using Lab9.StatusPrint;
namespace Lab9.FolderPrinter
{
    public class LaserPrinter : Printer, ILaser
    {
        public LaserPrinter(string name, PrintStatus status) : base(name, status)
        {

        }
        public override void MethodPrint()
        {
            Console.WriteLine("I can print some information using laser");
        }

        public string Laser { get; }
    }
}