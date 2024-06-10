using System.Numerics;

namespace Lab7
{
    public class Complex
    {
        double FirstReal { get; set; }
        double SecondReal { get; set; }
        public Complex(double firstReal, double secondReal)
        {
            this.FirstReal = firstReal;
            this.SecondReal = secondReal;
        }
        public static Complex operator +(Complex firstComplex, Complex secondComplex)
        {
            Complex result = new Complex(0, 0);
            result.FirstReal = firstComplex.FirstReal + secondComplex.FirstReal;
            result.SecondReal = firstComplex.SecondReal + secondComplex.SecondReal;
            return result;
        }
        public static Complex operator -(Complex firstComplex, Complex secondComplex)
        {
            Complex result = new Complex(0, 0);
            result.FirstReal = firstComplex.FirstReal - secondComplex.FirstReal;
            result.SecondReal = firstComplex.SecondReal - secondComplex.SecondReal;
            return result;
        }
        public static Complex operator *(Complex firstComplex, Complex secondComplex)
        {
            Complex result = new Complex(0, 0);
            result.FirstReal = firstComplex.FirstReal * secondComplex.FirstReal - firstComplex.SecondReal * secondComplex.SecondReal;
            result.SecondReal = firstComplex.FirstReal * secondComplex.SecondReal + firstComplex.SecondReal * firstComplex.FirstReal;
            return result;
        }
        public static bool operator ==(Complex firstComplex, Complex secondComplex)
        {
            return (firstComplex.FirstReal == secondComplex.FirstReal && firstComplex.SecondReal == secondComplex.SecondReal);
        }
        public static bool operator !=(Complex firstComplex, Complex secondComplex)
        {
            return Convert.ToBoolean(firstComplex.FirstReal != secondComplex.FirstReal || firstComplex.SecondReal != secondComplex.SecondReal);
        }
        public static Complex operator +(Complex firstComplex, double number)
        {
            Complex result = new Complex(0, firstComplex.SecondReal);
            result.FirstReal = firstComplex.FirstReal + number;
            return result;
        }
        public static Complex operator -(Complex firstComplex, double number)
        {
            Complex result = new Complex(0, firstComplex.SecondReal);
            result.FirstReal = firstComplex.FirstReal - number;
            return result;
        }
        public static Complex operator *(Complex firstComplex, double number)
        {
            Complex secondComplex = new Complex(number, 0);
            Complex result = new Complex(0, 0);
            result.FirstReal = firstComplex.FirstReal * secondComplex.FirstReal - firstComplex.SecondReal * secondComplex.SecondReal;
            result.SecondReal = firstComplex.FirstReal * secondComplex.SecondReal + firstComplex.SecondReal * firstComplex.FirstReal;
            return result;
        }
        public static bool operator ==(Complex firstComplex, double number)
        {
            return (firstComplex.FirstReal == number && firstComplex.SecondReal == 0);
        }
        public static bool operator !=(Complex firstComplex, double number)
        {
            return (firstComplex.FirstReal != number || firstComplex.SecondReal != 0);
        }

        public static implicit operator Complex(double number)
        {
            return new Complex(number, 0);
        }

        public static explicit operator double(Complex complex)
        {
            return complex.FirstReal;
        }
        public static bool operator false(Complex complex)
        {
            return (complex.FirstReal == 0 && complex.SecondReal == 0);
        }
        public static bool operator true(Complex complex)
        {
            return (complex.FirstReal != 0 || complex.SecondReal != 0);
        }
        public static Complex operator ++(Complex complex)
        {
            return new Complex(complex.FirstReal + 1, complex.SecondReal);
        }
        public static Complex operator --(Complex complex)
        {
            return new Complex(complex.FirstReal - 1, complex.SecondReal);
        }
        public override string ToString()
        {
            if (this.SecondReal < 0)
            {
                double secondRealComplex = this.SecondReal;
                secondRealComplex *= -1;
                return (this.FirstReal.ToString() + "-" + secondRealComplex.ToString() + "i");
            }
            return (this.FirstReal.ToString() + "+" + this.SecondReal.ToString() + "i");
        }
    }
}
