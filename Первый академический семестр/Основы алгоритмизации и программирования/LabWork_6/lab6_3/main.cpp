#include <iostream>
#include <cstring>
#include <iomanip>
#include "../staticlib/staticlib.h"


int const SIZE = 100;

bool check_for_number(char a) {
	return (((int)a >= 48 && (int)a <= 57) ? 1 : 0);

}

bool check_for_dot(char a) {
	return (((int)a == 46) ? 1 : 0);
}

int powl(int a, int b) {
	if (b == 0) return 1;
	else return a * powl(a, b - 1);
}

double powl_double(int a, int b) {
	if (b == 0) return 1;
	else if (b > 0) return a * powl_double(a, b - 1);
	else return powl_double(a, b + 1) / a;
}

int reverse_to_int(char* mass, int SIZE) {
	int k = 0;
	int result = 0;
	if (mass[0] == '-') {
		if (check_for_number(mass[0]) == 1) k++;
		for (int i = 1; i < SIZE; i++) {
			if (check_for_number(mass[i]) == 1) k++;
			else break;
		}
		for (int i = k; i >= 1; i--) {
			result += powl(10, k - i) * (mass[i] - 48);
		}
		result *= -1;
	}
	else {
		for (int i = 0; i < SIZE; i++) {
			if (check_for_number(mass[i]) == 1) k++;
			else break;
		}
		for (int i = k - 1; i >= 0; i--) {
			result += powl(10, k - i - 1) * (mass[i] - 48);
		}
	}
	return result;
}

double reverse_to_double(char* mass, int SIZE) {
	int k = 0;
	double result = 0;
	if (mass[0] == '-') {
		int i = 1;
		for (; i < SIZE; i++) {
			if (check_for_number(mass[i]) == 1) k++;
			else break;
		}
		for (int p = k; p >= 1; p--) {
			result += powl(10, k - p) * (mass[p] - 48);
		}
		if (check_for_dot(mass[i]) == 1) {
			i++;
			for (int t = -1;;t--, i++) {
				if (check_for_number(mass[i]) == 1) {
					result += powl_double(10, t) * (mass[i] - 48);
				}
				else break;
			}
		}
		result *= -1.0;
	}
	else {
		int i = 0;
		for (; i < SIZE; i++) {
			if (check_for_number(mass[i]) == 1) k++;
			else break;
		}
		for (int p = k - 1; p >= 0; p--) {
			result += powl(10, k - p - 1) * (mass[p] - 48);
		}
		if (check_for_dot(mass[i]) == 1) {
			i++;
			for (int t = -1;;t--, i++) {
				if (check_for_number(mass[i]) == 1) {
					result += powl_double(10, t) * (mass[i] - 48);
				}
				else break;
			}
		}
	}
	return result;
}

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр\nГруппа 353502\nУсловие задания:написать функции перевода целых чисел в строку и строки в число; функции перевода вещественных чисел в строку, перевода строки в вещественное число.Стандартных функций работы со строками не использовать.\n\n\n";
	int continuation = 1;
	while (continuation == 1) {
		std::cout << "1.Преобразовать строку в целое число\n2.Преобразовать строку в вещественное число\nВыберите продолжение:";
		int next;
		std::cin >> next;
		char mass[SIZE];
		cin_str_double(mass, SIZE);
		if (next == 1) std::cout << reverse_to_int(mass, SIZE);
		else std::cout << reverse_to_double(mass, SIZE);
		std::cout << '\n' << "Хотите проделать операцию ещё раз?(1 - да, 2 - нет)\n";
		std::cout << "Введите продолжение:";
		std::cin >> continuation;
		std::cout << "\n\n";
	}
	std::cout << "Спасибо за внимание!!!";
}