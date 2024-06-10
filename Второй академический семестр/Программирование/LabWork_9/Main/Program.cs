using Lab9;
using Lab9.Builder;
using Lab9.FolderPrinter;

var printers = new List<Printer>();
var _builderInkjetPrinter = new BuilderInkjetPrinter();
var _builderLaserPrint = new BuilderLaserPrint();
var _builderPrinter3D = new BuilderPrinter3D();

printers.Add(Director.GetInkjetPrinterWorkBlackWhite("Canon", _builderInkjetPrinter));
printers.Add(Director.GetLaserPrinterWorkBlackWhite("HP", _builderLaserPrint));
printers.Add(Director.GetLaserPrinterWorkColor("Epson", _builderLaserPrint));
printers.Add(Director.Get3DPrinterWorkBlackWhite("Canon", _builderPrinter3D));

foreach (Printer printer in printers)
{
    printer.MethodPrint();
}

printers[0].Power(true);
printers[1].Power(false);