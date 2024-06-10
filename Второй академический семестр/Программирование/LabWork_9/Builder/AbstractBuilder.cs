using Lab9.FolderPrinter;
using Lab9.ImplementationOfPrint;
using Lab9.StatusPrint;

namespace Lab9
{
    public abstract class AbstractBuilder
    {

        protected string name = String.Empty;
        protected PrintStatus status;
        protected IImplementationOfPrint? PrintMethod;
        public AbstractBuilder SetName(string name)
        {
            this.name = name;
            return this;
        }
        public AbstractBuilder SetStatus(PrintStatus status)
        {
            this.status = status;
            return this;
        }
        public AbstractBuilder SetMethod(IImplementationOfPrint PrintMethod)
        {
            this.PrintMethod = PrintMethod;
            return this;
        }
        public abstract Printer Build();
    }

    public class BuilderInkjetPrinter : AbstractBuilder
    {
        public override Printer Build()
        {
            var inkjetPrinter  = new InkjetPrinter (name, status);
            if(SetMethod != null)
            {
                inkjetPrinter.setImplementationOfPrint(PrintMethod);
            }
            return inkjetPrinter;
        }
    }

    public class BuilderLaserPrint : AbstractBuilder
    {
        public override Printer Build()
        {
            var laserPrinter = new LaserPrinter(name, status);
            if (SetMethod != null)
            {
                laserPrinter.setImplementationOfPrint(PrintMethod);
            }
            return laserPrinter;
        }
    }
    public class BuilderPrinter3D : AbstractBuilder
    {
        public override Printer Build()
        {
            var printer3D = new Printer3D(name, status);
            if (SetMethod != null)
            {
                printer3D.setImplementationOfPrint(PrintMethod);
            }
            return printer3D;
        }
    }
}
