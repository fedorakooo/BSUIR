using Math;
using Services;
using DateServiceClassLibrary;

class Task
{
    public static int correctInputInt(string communication)
    {
        int result =  0;
        bool wrong = true;
        do
        {
            Console.Write(communication);
            string text = Console.ReadLine();
            if (int.TryParse(text, out result))
            {
                wrong = false;
            }
        } while (wrong);
        return result;
    }
    
    public static double correctInputDouble(string communication)
    {
        double result =  0;
        bool wrong = true;
        do
        {
            Console.Write(communication);
            string text = Console.ReadLine();
            if (double.TryParse(text, out result))
            {
                wrong = false;
            }
        } while (wrong);
        return result;
    }
    
    public static DateTime correctInputDateTime(string communication)
    {
        DateTime result;
        bool wrong = true;
        do
        {
            Console.Write(communication);
            string text = Console.ReadLine();
            if (DateTime.TryParse(text, out result))
            {
                wrong = false;
            }
        } while (wrong);
        
        return result;
    }
    
    public static DateTime correctInputDateTimeInt()
    {
        bool wrong = true;
        int day, month, year;

        do
        {
            day = correctInputInt("\nВведите значение дня: ");
            month = correctInputInt("Введите значение месяца: ");
            year = correctInputInt("Введите значение года: ");
            
            if (day > 0 && month > 0 && month <= 12 && year >= -4173 && year < 9999)
            {
                if (DateTime.DaysInMonth(year, month) >= day)
                {
                    wrong = false;
                }
            }
            
        } while (wrong);
        
        DateTime result = new DateTime(year, month, day);

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
                working = correctInputInt("Введите вариант продолжения: ");    
            } while (working != 1 && working != 0);

            if (working == 1)
            {
                int numberTask;
                Console.WriteLine("\nУсловия заданий для выполнения\n1.Разработать метод min(a,b) для нахождения минимального из двух чисел.\n2.Разработать метод для вычисления значения функции в соответствии с индивидуальным вариантом.\n3.Разработать класс DateService.\n");
                
                do
                {
                    numberTask = correctInputInt("Введите номер задания: ");    
                } while (numberTask != 1 && numberTask != 2 && numberTask != 3);
                
                switch (numberTask)
                {
                    case 1:
                    {
                        Console.WriteLine("\nУсловие задания для выполнения: Разработать метод min(a,b) для нахождения минимального из двух чисел.");
                        ClassMath procedures = new ClassMath();
                        int x;
                        x = correctInputInt("\nВведите первое число: ");
                        int y;
                        y = correctInputInt("Введите второе число: ");
                        Console.WriteLine("\nВычислим значение необходимой формулы: z=max(x,2y+x)-max(7x+2y,y)");
                        int z = procedures.min(x, 2 * y + x) - procedures.min(7*x+2*y,y);
                        Console.WriteLine("\nРезультат: {0}", z);
                        break;
                    }
                    case 2:
                    {
                        Console.WriteLine("\nУсловие задания для выполнения: Разработать метод для вычисления значения функции в соответствии с индивидуальным вариантом.");
                        ClassServices procedures = new ClassServices();
                        double x;
                        x = correctInputDouble("\nВведите первое число: ");
                        double y;
                        y = correctInputDouble("Введите второе число: ");
                        
                        if (x < 1) Console.WriteLine("\nИсполняется первая ветка формулы");
                        else Console.WriteLine("\nИсполняется вторая ветка формулы");
                        
                        Console.WriteLine("\nВычислим значение необходимой формулы");

                        double z = procedures.getResult(x, y);
                        Console.WriteLine("Результат: {0}", z);
                        break;
                    }
                    case 3:
                    {
                        Console.WriteLine("\nУсловие задания для выполнения: Описать класс DateService. Класс должен предоставлять следующие методы: Определять день недели произвольной даты, передаваемой методу в качестве строкового параметра, определять, сколько дней пройдет между текущей датой и датой, передаваемой методу в качестве числовых параметров: день, месяц, год\n");
                        DateService procedures = new DateService();
                        int next;
                        do
                        { 
                            next = correctInputInt("Выберите номер из двух предыдущих заданий: ");
                        }  while (next != 1 && next != 2);

                        if (next == 1)
                        {
                            Console.WriteLine("\nУсловие задания для выполнения: Метод должен определять день недели произвольной даты, передаваемой методу в качестве строкового параметра\n");
                            DateTime date;
                            
                            date = correctInputDateTime("Введите: ");
                            Console.Write("\nРезультат: ");
                            Console.WriteLine(procedures.GetDay(date));
                        }
                        else
                        {
                            
                            Console.WriteLine( "\nУсловие задания для выполнения: Метод должен определять,сколько дней пройдет между текущей датой и датой, передаваемой методу в качестве числовых параметров: день, месяц, год");

                            DateTime date = correctInputDateTimeInt();
                            
                            Console.Write("\nРезультат:");
                            
                            Console.WriteLine(procedures.GetDaysSpan(date));
                        }
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