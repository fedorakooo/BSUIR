using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab9.ImplementationOfPrint
{
    public interface IImplementationOfPrint
    {
        public string PrintImplementation();
    }

    public class ImplementationOfOnePage : IImplementationOfPrint
    {
        public string PrintImplementation()
        {
            return "One page print";
        }
    } 
    public class ImplementationOfAllPage : IImplementationOfPrint
    {
        public string PrintImplementation()
        {
            return "All page print";
        }
    }
    public class ImplementationOfSomePage : IImplementationOfPrint
    {
        public string PrintImplementation()
        {
            return "Some page print";
        }
    }
}
