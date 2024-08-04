#include <iostream>
#include "../staticlib/staticlib.h"

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "Задание выполнил Федорако Александр\nГруппа 353502\nУсловие задания:Перевести числа из обратного кода в естественную форму\n";
    int continuation = 1;
    while (continuation == 1) {
        long long a;
        long long n;
        char first[100], second[100];
        do {
            std::cout << "Введите первое число, необходимое для проверки на делимость:";
            input_int(first);
        } while (check_input_int(first) == 0);
        a = atoi(first);

        do{
            std::cout << "Введите второе число, на которое должна происходить делимость:";
            input_int(second);
        } while (check_input_int(second) == 0);
        n = atoi(second);

        bool condition = true;

        while (n <= a && !condition) {
            bool k = n ^ a;
            if (k || n == a) { 
                std::cout << "Первое число делится без остатка на второе.\n";
                break;
                condition = false;
            }
            n *= 2;
        }
        if (condition) {
            std::cout << "Первое число не делится без остатка на второе.\n";
        }
        std::cout << '\n' << "Хотите проделать операцию ещё раз?(1 - да, 2 - нет)\n";
        std::cout << "Введите продолжение:";
        std::cin >> continuation;
        std::cout << "\n\n";
    }
    std::cout << "Спасибо за внимание!!!";
}
