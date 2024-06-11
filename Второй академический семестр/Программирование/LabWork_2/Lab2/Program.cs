class Task
{
    
    public static int correctInputInt()
    {
        int result = 0;
        bool wrong = true;
        do
        {
            Console.Write("Введите число: ");
            string text = Console.ReadLine();
            if (int.TryParse(text, out result))
            {
                wrong = false;
            }
        } while (wrong);
        return result;
    }
    
    public static double correctInputDouble()
    {
        double result = 0;
        bool wrong = true;
        do
        {
            Console.Write("Введите число: ");
            string text = Console.ReadLine();
            if (double.TryParse(text, out result))
            {
                wrong = false;
            }
        } while (wrong);
        return result;
    }
    
    static void Main()
    {
        int working = 0;
        do
        {
            Console.WriteLine("Введите вариант продолжения выполнения программы");
            Console.WriteLine("Введите число 1 для выполнения одного из заданий в лабораторной работе");
            Console.WriteLine("Введите число 0 для завершения работы программы");
            do
            {
                working = correctInputInt();    
            } while (working != 1 && working != 0);

            if (working == 1)
            {
                int numberTask;
                Console.WriteLine("\nВведите номер задания, необходимого к решению");
                Console.WriteLine("1.Определелить, какая из цифр двузначного числа больше: первая или вторая");
                Console.WriteLine("2.Определить нахождение точки с задающимися координатами относительно определенной фигуры");
                  
                do
                {
                    numberTask = correctInputInt();    
                } while (numberTask != 1 && numberTask != 2);
                
                switch (numberTask)
                {
                    case 1:
                    {
                        Console.WriteLine("Введите необходимое число");
                        int x;
                        do
                        {
                            x = correctInputInt();
                        } while (!(Math.Abs(x) > 9 && Math.Abs(x) < 100));
                        
                        int a1 = x % 10;
                        int a2 = x / 10;
                        if (a1 > a2)
                        {
                            Console.WriteLine("Число единиц больше числа десятков");
                        }
                        else if (a2 > a1)
                        {
                            Console.WriteLine("Число десятков больше числа единиц");
                        }
                        else
                        {          
                            Console.WriteLine("Число десятков равно числу единиц");
                        }
                        break;
                    }
                    case 2:
                    {
                        double pointX, pointY;
                        Console.WriteLine("Введите координаты точки по оси Ox");
                        pointX = correctInputDouble();
                        Console.WriteLine("Введите координаты точки по оси Oy");
                        pointY = correctInputDouble();
                        double radius;
                        radius = Math.Sqrt(Math.Pow(pointX, 2) + Math.Pow(pointY, 2));
                        if (radius == 3.0 || radius == 7.0)
                            Console.WriteLine("Нахождение точки: на границе заштрихованой плоскости");
                        else if (radius < 7.0 && radius > 3.0)
                            Console.WriteLine("Нахождение точки: внутри заштрихованой плоскости");
                        else
                            Console.WriteLine("Нахождение точки: вне заштрихованой плоскости");
                        break;
                    }
                    default:
                    {
                        Console.WriteLine("Не удалось распознать число, попробуйте еще раз.");
                        break;
                    }
                };
                Console.Write("\n");
            }
            else
            {
                Console.Write("\nСпасибо за внимание!");
            }
        } while (working != 0);
    }
}