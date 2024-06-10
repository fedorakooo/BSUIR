using Lab9.ImplementationOfPrint;
using Lab9.StatusPrint;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab9.FolderPrinter
{
    public abstract class Printer
    {
        public string Name { get; set; }
        int NumberPages { get; set; }

        protected IImplementationOfPrint _implementationOfPrint;
        public PrintStatus EnumStatusPrint { get; set; }

        public Printer(string name, PrintStatus status)
        {
            Name = name;
            EnumStatusPrint = status;
        }

        public virtual void Print()
        {
            Console.WriteLine("Base operation with print");
        }

        public void setImplementationOfPrint(IImplementationOfPrint implementationOfPrint)
        {
            _implementationOfPrint = implementationOfPrint;
        }
        public void GetInfo()
        {
            Console.WriteLine("I can print some information");
        }
        public void Power(bool status)
        {
            if (status)
            {
                Console.WriteLine($"{Name} status: power on");
            }
            else
            {
                Console.WriteLine($"{Name} status: power off");
            }
        }
        public abstract void MethodPrint();
    }
}
