#include <iostream>
#include "../staticlib/staticlib.h"

bool check_for_number(char a) {
	return (((int)a >= 48 && (int)a <= 57) ? 1 : 0);
}

bool check_for_dot(char a) {
	return (((int)a == 46) ? 1 : 0);
}

bool check_for_minus(char a) {
	return (((int)a == 45) ? 1 : 0);
}

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр\nГруппа 353502\nУсловие задания:Из строки, состоящей из букв, цифр, запятых, точек, знаков + (плюс) и–(минус), выделить подстроку, задающую вещественное число с плавающей точкой.\n";
	char condition[100];
	do {
		char line[100];
		std::cout << "Введите строку:";
		for (int i = 0; i < 100; i++) {
			line[i] = getchar();
			if (line[i] == '\n' && i > 0) {
				line[i] = '\0';
				break;
			}
		}
		std::cout << "Числа, входимые в данную строку\n";
		for (int i = 0; i < sizeof(line) - 1 && line[i] != '\n'; i++) {
			if (line[i] == '0') std::cout << '0' << '\n';
			else if (check_for_number(line[i]) == 1 && line[i] != '0') {
				if (i > 0) {
					if (line[i - 1] == '-') std::cout << '-';
				}
				bool dot = 0;
				for (; i < sizeof(line) - 1; i++) {
					if (check_for_number(line[i]) == 1) {
						std::cout << line[i];
						if (check_for_number(line[i + 1]) == 0 && check_for_dot(line[i + 1]) == 0 && dot == 0) {
							std::cout << ".0";
						}
					}
					else if (check_for_dot(line[i]) == 1 && dot == 0) {
						std::cout << line[i];
						dot = 1;
						if (check_for_number(line[i + 1]) == 0) std::cout << 0;
					}
					else break;
				}
				std::cout << '\n';
			}
		}
		std::cout << '\n' << "Хотите проделать операцию ещё раз?(1 - да, 2 - нет)\n";
		do {
			std::cout << "Введите продолжение:";
			for (int i = 0;i < 100;i++) {
				condition[i] = getchar();
				if (condition[i] == '\n' && i > 0) {
					condition[i] = '\0';
					break;
				}
			}
		} while (!(input_check_int(condition) && (condition[0] == '2' || condition[0] == '1')));
		std::cout << "\n\n";
	} while (condition[0] == '1');
	std::cout << "Спасибо за внимание!!!";
}