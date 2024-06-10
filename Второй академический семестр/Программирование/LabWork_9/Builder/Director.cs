using Lab9.FolderPrinter;
using Lab9.StatusPrint;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab9.Builder
{
    public class Director
    {
        public static Printer GetInkjetPrinterWorkColor(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetStatus(PrintStatus.color).Build();
        }
        public static Printer GetInkjetPrinterWorkBlackWhite(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetStatus(PrintStatus.black_white).Build();
        }
        public static Printer GetLaserPrinterWorkColor(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetStatus(PrintStatus.color).Build();
        }
        public static Printer GetLaserPrinterWorkBlackWhite(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetStatus(PrintStatus.black_white).Build();
        }
        public static Printer Get3DPrinterWorkColor(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetStatus(PrintStatus.color).Build();
        }
        public static Printer Get3DPrinterWorkBlackWhite(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetStatus(PrintStatus.black_white).Build();
        }
    }
}
