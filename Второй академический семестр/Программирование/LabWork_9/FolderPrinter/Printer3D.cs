using Lab9.StatusPrint;

namespace Lab9.FolderPrinter
{
    public class Printer3D : Printer, I3DBlock
    {
        public Printer3D(string name, PrintStatus status) : base(name, status)
        {

        }
        public override void MethodPrint()
        {
            Console.WriteLine("I can print some information using ABC plastic");
        }
        public string Block { get; set; }

    }
}
