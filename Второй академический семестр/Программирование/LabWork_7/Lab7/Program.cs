namespace Lab7;
using System.Numerics;

class Program
{
    static void Main(string[] args)
    {
        Complex firstComplex = new Complex(12, 12);
        Complex secondComplex = new Complex(11, 16);
        Console.WriteLine("First complex:\t" + firstComplex.ToString());
        Console.WriteLine("Second complex:\t" + secondComplex.ToString());
        Console.WriteLine("+\t\t" + (firstComplex + secondComplex).ToString());
        Console.WriteLine("-\t\t" + (firstComplex - secondComplex).ToString());
        Console.WriteLine("*\t\t" + (firstComplex * secondComplex).ToString());
        Console.WriteLine("==\t\t" + (firstComplex == secondComplex));
        Console.WriteLine("!=\t\t" + (firstComplex != secondComplex));

        double firstNumber = 12;
        Console.WriteLine("\nFirst number:\t" + firstNumber.ToString());
        Console.WriteLine("+\t\t" + (firstComplex + firstNumber).ToString());
        Console.WriteLine("-\t\t" + (firstComplex - firstNumber).ToString());
        Console.WriteLine("*\t\t" + (firstComplex * firstNumber).ToString());
        Console.WriteLine("==\t\t" + (firstComplex == firstNumber));
        Console.WriteLine("!=\t\t" + (firstComplex != firstNumber));
    }
}