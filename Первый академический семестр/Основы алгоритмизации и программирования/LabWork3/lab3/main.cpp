#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "ru");
    const long double E = 2.71828182845904523536028747135266249775724709369995;
    const long double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811;
    std::cout << "Выполнил задания Федорако Александр Анатольевич, группа 353502\n" << "Номер в списке группы:23\n" << "Вариант выполнения задания:8\n";
    while (true) {
        std::cout << "Введите номер задания: ";
        int number;
        while (!(std::cin >> number) || (std::cin.peek() != '\n'))
        {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "\n" << "Некорректный ввод" << "\n";
            std::cout << "Введите номер задания: ";
        }
        if (number < 1 || number > 9) {
            std::cout << "\n" << "Некорректный ввод" << "\n" << "\n";
            continue;
        }
        if (number == 1) {
            long N = 0;
            int ai, bi;
            for (int i = 1; i <= 30; i++) {
                if (i % 2 == 1) {
                    ai = i;
                    bi = i * i;  
                }
                else {
                    ai = i / 2;
                    bi = i * i * i;
                }
                N += (ai - bi) * (ai - bi);
            }
            std::cout << N;
        }
        if (number == 2) {
            int n = 1;
            double result = 0;
            double const e = 0.001;
            do {
                result += 1 / powl(2, n) + 1 / powl(3, n);
                n++;
            } while (1 / powl(2, n) + 1 / powl(3, n) >= e);
            std::cout << result;
        }
        if (number == 3) {
            double B = acos(-1) / 2;
            double x, A = 0, H, M = 20;
            H = (B - A) / M;
            for (int i = 0; ; i++) {
                x = A + i * H;
                if (x > B) break;
                double y = sin(x) - cos(x);
                std::cout << '\n' << y;
            }
        }
        if (number == 4) {
            long double n;
            std::cout << "Какую из вариаций решения хотите использовать?\n1.С использованием цикла\n2.Без использования цикла\nВведите вариант решения задания:";
            while (!(std::cin >> n) || (std::cin.peek() != '\n'))
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "\n" << "Некорректный ввод" << "\n";
                std::cout << "Какую из вариаций решения хотите использовать?\n1.С использованием цикла\n2.Без использования цикла\nВведите вариант решения задания:";

            }
            double x;
            std::cout << "\n";
            std::cout << "Введите конечное число: ";
            while (!(std::cin >> x) || (std::cin.peek() != '\n'))
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "\n" << "Некорректный ввод" << "\n";
                std::cout << "Введите конечное число: ";

            }
            int d = x;
            if (n == 1) {
                int summa = 0;
                for (int i = 1; i != d + 1; i++) {
                    if (i % 2 == 0) {
                        summa = summa + i;
                    }
                }
                std::cout << summa;
            }
            else if (n == 2) {
                int a1 = 2;
                int an;
                if (d % 2 == 1) an = d - 1;
                else an = d;
                int n = an / 2;
                int summa = (a1 + an) / 2 * n;
                std::cout << summa;
            }
            else {
                std::cout << "\n" << "Некорректный ввод" << "\n";
            }
        }
        if (number == 5) { //8
            long long int n, k;
            std::cout << "Введите количество членов ряда n:";
            while (!(std::cin >> n) || (std::cin.peek() != '\n'))
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "\n" << "Некорректный ввод" << "\n";
                std::cout << "Введите количество членов ряда n: ";

                
            }
            std::cout << "Введите количество вычислений: ";
            while (!(std::cin >> k) || (std::cin.peek() != '\n'))
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "\n" << "Некорректный ввод" << "\n";
                std::cout << "Введите количество вычислений: ";

                
            }
            for (; k > 0; k--) {
                double x;
                std::cout << "Введите значение переменной x: ";
                std::cin >> x;
                if (x < 0.1 || x > 1) {
                    std::cout << "Ошибка" << "\n";
                }
                else {
                    long double ex = 1;
                    for (int m = 1; m < n; m++) {
                        long long int factorial = 1;
                        for (int f = 1; f <= m; f++) {
                            factorial *= f;
                        }
                        ex += powl(2 * x, m) / factorial;
                    }
                    std::cout << "Вычисленное значение e^2x равно: " << ex << "\n";
                    long double ex1 = exp(2 * x);
                    std::cout << "Вычисленное значение e^2x с помощью стандартной функции равно: " << ex1 << "\n" << "\n";
                }
            }
        }
        if (number == 6) { //8
            std::cout << "Введите на какое количество необходимо разбить исходный промежуток: ";
            long double chasti;
            while (!(std::cin >> chasti) || (std::cin.peek() != '\n'))
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "\n" << "Некорректный ввод" << "\n";
                std::cout << "Введите на какое количество необходимо разбить исходный промежуток: ";
            }
            long double shag;
            shag = 1 / chasti;
            long double minX = 0.5, maxX = 1.5;
            long double resultmin = fabs(sqrt(cos(minX)) + log(sin(minX)) - 0.5);
            long double result = resultmin;
            long double  resultX = minX;
            for (long double x = minX + shag; x < maxX; x += shag) {
                long double result = fabs(sqrt(cos(x)) + log(sin(x)) - 0.5);
                long double resultS = result;
                if(resultS < 0) resultS = -resultS;
                if (resultS < resultmin) {
                    resultmin = resultS;

                    resultX = x;
                }
            }
            std::cout << "Полученный x равен: ";
            std::cout << resultX << "\n";
            std::cout << "Результат вычисления через промежутки: ";
            std::cout << resultmin << "\n";
        }
        if (number == 7) {
            int num;
            std::cout << "1.Проверить тесты, написанные раннее на доске\n2.Проверить тест, введенный пользователем\n\n";
            std::cout << "Введите дальнейший вариант проверки задания: ";
            while (!(std::cin >> num) || (std::cin.peek() != '\n'))
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "\n" << "Некорректный ввод" << "\n";
                std::cout << "Введите дальнейший вариант проверки задания: ";
            }
            if (num != 1 && num != 2) {
                std::cout << "\n" << "Некорректный ввод" << "\n" << "\n";
                continue;
            }
            if (num == 1) {
                long double mass[10]{ 0.00001, 0.1, 1, 1.9, 2.1, 2.7, 2.9, 10, 1000, 1000000 };
                std::cout << "Проверяемые данные:";
                for (int i = 0; i < 10; i++) {
                    std::cout << mass[i] << ',';
                }
                for (int i = 0; i < 10; i++) {
                    std::cout << "\n\n";
                    long double x;
                    x = mass[i];
                    //1
                    std::cout << "\nПроверяемое значение равно:" << mass[i];
                    long double result1 = 0, result2 = 0, result3 = 0;
                    long double x1 = x;
                    //sin x
                    for (;x1 < -2 * PI; x1 += 2 * PI);
                    for (;x1 > 2 * PI; x1 -= 2 * PI);
                    for (long int n1 = 1, n2 = 3; n1 < 56; n1 += 4, n2 += 4) {
                        long double factorial1 = 1, factorial2 = 1;
                        for (int i = 1; i <= n1; i++) {
                            factorial1 *= i;
                        }
                        for (int i = 1; i <= n2; i++) {
                            factorial2 *= i;
                        }
                        result1 = result1 + std::powl(x1, n1) / factorial1 - std::powl(x1, n2) / factorial2;
                    }
                    //cos x
                    for (long int n1 = 0, n2 = 2; n1 < 56; n1 += 4, n2 += 4) {
                        for (;x1 < -2 * PI; x1 += 2 * PI);
                        for (;x1 > 2 * PI; x1 -= 2 * PI);

                        long double factorial1 = 1, factorial2 = 1;
                        for (int i = 1; i <= n1; i++) {
                            factorial1 *= i;
                        }
                        for (int i = 1; i <= n2; i++) {
                            factorial2 *= i;
                        }
                        result2 = result2 + powl(x1, n1) / factorial1 - powl(x1, n2) / factorial2;
                    }
                    //ln x
                    long double x3 = x;
                    if (x3 < 0) x3 = -x3;
                    while (x3 > pow(E, 1000000)) {
                        result3 += 1000000;
                        x3 /= powl(E, 1000000);
                    }
                    while (x3 > pow(E, 1000)) {
                        result3 += 1000;
                        x3 /= powl(E, 1000);
                    }
                    while (x3 > 1) {
                        result3++;
                        x3 /= E;
                    }
                    x3--;
                    for (long int a = 1, b = 2; a < 1000000; a += 2, b += 2) {
                        result3 += std::powl(x3, a) / a - std::powl(x3, b) / b;
                    }
                    std::cout << "\n\nСинус x библиотеки cmath равен: " << std::sin(x) << "\n";
                    std::cout << "Косинус x библиотеки cmath равен: " << std::cos(x) << "\n";
                    std::cout << "Натуральный логарифм x библиотеки cmath равен: " << std::log(x) << "\n\n";
                    std::cout << "Синус x равен: " << result1 << "\n";
                    std::cout << "Косинус x равен: " << result2 << "\n";
                    std::cout << "Натуральный логарифм x равен: " << result3 << "\n";
                    std::cout << "\n";
                    std::cout << "Минимальное значение равно: ";
                    if (result3 <= result2 && result3 <= result1) std::cout << result3;
                    else if (result2 <= result3 && result2 <= result1) std::cout << result2;
                    else std::cout << result1;
                    std::cout << "\n\n";

                }
            }
            else {
                long double x;
                std::cout << "Введите значение переменной x: ";
                while (!(std::cin >> x) || (std::cin.peek() != '\n'))
                {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "\n" << "Некорректный ввод" << "\n";
                    std::cout << "Введите значение переменной x: ";

                }
                long double result1 = 0, result2 = 0, result3 = 0;
                long double x1 = x;
                for (;x1 < -2 * PI; x1 += 2 * PI);
                for (;x1 > 2 * PI; x1 -= 2 * PI);
                for (long int n1 = 1, n2 = 3; n1 < 56; n1 += 4, n2 += 4) {
                    long double factorial1 = 1, factorial2 = 1;
                    for (int i = 1; i <= n1; i++) {
                        factorial1 *= i;
                    }
                    for (int i = 1; i <= n2; i++) {
                        factorial2 *= i;
                    }
                    result1 = result1 + powl(x1, n1) / factorial1 - powl(x1, n2) / factorial2;
                }
                long double x2 = x;
                for (long int n1 = 0, n2 = 2; n1 < 56; n1 += 4, n2 += 4) {
                    long double factorial1 = 1, factorial2 = 1;
                    for (int i = 1; i <= n1; i++) {
                        factorial1 *= i;
                    }
                    for (int i = 1; i <= n2; i++) {
                        factorial2 *= i;
                    }
                    result2 = result2 + powl(x1, n1) / factorial1 - powl(x1, n2) / factorial2;
                }
                long double x3 = x;
                if (x3 < 0) x3 = -x3;
                while (x3 > pow(E, 1000000)) {
                    result3 += 1000000;
                    x3 /= powl(E, 1000000);
                }
                while (x3 > pow(E, 1000)) {
                    result3 += 1000;
                    x3 /= powl(E, 1000);
                }
                while (x3 > 1) {
                    result3++;
                    x3 /= E;
                }
                x3--;
                for (long int a = 1, b = 2; a < 20000000; a += 2, b += 2) {
                    result3 += std::powl(x3, a) / a - std::powl(x3, b) / b;
                }
                std::cout << "\nСинус x библиотеки cmath равен: " << std::sin(x) << "\n";
                std::cout << "Косинус x библиотеки cmath равен: " << std::cos(x) << "\n";
                int x0 = x;
                if (x0 < 0) x0 = -x0;
                std::cout << "Натуральный логарифм x библиотеки cmath равен: " << std::log(x0) << "\n\n";
                std::cout << "Синус x равен: " << result1 << "\n";
                std::cout << "Косинус x равен: " << result2 << "\n";
                std::cout << "Натуральный логарифм x равен: " << result3 << "\n";
                std::cout << "\n";
                std::cout << "Минимальное значение равно: ";
                if (result3 <= result2 && result3 <= result1) std::cout << result3;
                else if (result2 <= result3 && result2 <= result1) std::cout << result2;
                else std::cout << result1;
                std::cout << "\n\n";
            }
        }
        if (number == 8) {
            std::cout << "Введите число: ";
            long int chislo;
            while (!(std::cin >> chislo) || (std::cin.peek() != '\n'))
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "\n" << "Некорректный ввод" << "\n";
                std::cout << "Введите число: ";

            }
            long int i = 1;
            for (; i < chislo; i++)
            {
                long int k = i, s = i, h = i;
                long int t = 0;
                long int a = 0;
                while (h != 0) {
                    a++;
                    h = h / 10;
                }
                while (k!=0) {
                    if (k % 10 == 0) {
                        k = k / 10;
                        continue;
                    }
                    else {
                        t = t + pow(k % 10, a);
                        k = k / 10;
                    }
                }
                if (t == s) std::cout << s << std::endl;
            }
        }
        if (number == 9) {
            long double a;
            long n;
            std::cout << "Введите значение переменной a: ";
            while (!(std::cin >> a) || (std::cin.peek() != '\n'))
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "\n" << "Некорректный ввод" << "\n";
                std::cout << "Введите значение переменной a: ";
            }
            std::cout << "Введите количество членов прогрессии n: ";
            std::cin >> n;
            while (!(std::cin >> n) || (std::cin.peek() != '\n'))
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "\n" << "Некорректный ввод" << "\n";
                std::cout << "Введите количество членов прогрессии n: ";

            }
            long double q = -2, b1= 1;
            long double summ = (b1 * (pow(q, n) - 1) / (q - 1));
            long double result = summ * a;
            std::cout << result;
        }
        std::cout << "\n\n";
    }
}