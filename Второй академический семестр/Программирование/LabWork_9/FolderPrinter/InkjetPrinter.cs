using Lab9.FolderPrinter;
using Lab9.StatusPrint;

namespace Lab9.FolderPrinter
{
    public class InkjetPrinter : Printer, ICartridge
    {
        public InkjetPrinter(string name, PrintStatus status) : base(name, status) {

        }
        public override void MethodPrint()
        {
            Console.WriteLine("I can print some information using ink");
        }
        public string Cartridge { get; set; }

    }
}
