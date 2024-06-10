using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7
{
    internal class IntInput
    {
        static public int Input(out bool flag)
        {
            try
            {
                flag = true;
                int number = int.Parse(Console.ReadLine());
                if (number > 0) return number;
                else throw new Exception("Было введенно отрицательное число");

            }
            catch
            {
                flag = false;
                return -1;
            }
        }
    }
}
