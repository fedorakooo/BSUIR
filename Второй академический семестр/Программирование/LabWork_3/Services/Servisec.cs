namespace Services;

public class ClassServices
{
    private double branching(double z, double b)
    {
        if (z < 1) return z / b;
        else return Math.Pow(z * b, 1.5);
    }
    public double getResult(double z, double b)
    {
        double x = branching(z, b);
        return (-Math.PI + Math.Pow(Math.Cos(Math.Pow(x, 3)), 2) + Math.Pow(Math.Sin(Math.Pow(x, 2)), 3));
    }
}