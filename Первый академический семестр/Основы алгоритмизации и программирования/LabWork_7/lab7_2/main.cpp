#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
#include "../staticlib/staticlib.h"

int const SIZE = 128;

void conclution(char* mass) { // O(n)
	for (int i = 0; mass[i] != '\0'; i++) {
		if(mass[i] != 'M') std::cout << mass[i];
    }
	std::cout << '\n';
}

// из естественной формы в прямой код
void from_norm_to_right_code(int value, char* right_code, int size) { // O(n)
	bool minus = (value >= 0 ? 0 : 1);
	if (minus == 1) value *= -1;
	int i = 0;
 	for (; value != 0 && i < SIZE; i++) { 
		if (value % 2 == 0) {
			right_code[i] = '0';
			value /= 2;
		}
		else {
			right_code[i] = '1';
			value /= 2;
		}
	}
	right_code[i] = (minus ? '1' : '0');
	right_code[i + 1] = '\0';
	_strrev(right_code);
}

// из прямого в обратный код
void from_right_to_result_code(char* right_code, char* result_code, int size) { // O(n)
	if (right_code[0] == '1') {
		result_code[0] = '1';
		for (int i = 1; right_code[i] != '\0'; i++) {
			if (right_code[i] == '1') result_code[i] = '0';
			else result_code[i] = '1';
			if (right_code[i + 1] == '\0') result_code[i + 1] = '\0';
		}
 	}
	else {
		for (int i = 0; right_code[i] != '\0'; i++) {
			result_code[i] = right_code[i];
			if (right_code[i + 1] == '\0') result_code[i + 1] = '\0';
		}	
	}
}

// преобразование строки
void change_for_addition(char* first_result_code, char* second_result_code) { // O(n)
	long long length1 = strlen(first_result_code);
	long long length2 = strlen(second_result_code);
	if (length1 > length2) {
		char save = second_result_code[0];
		char change[SIZE];
		std::strcpy(change, second_result_code);
		int i = 0;
		if (second_result_code[0] == '0') {
			for (; i < length1 - length2; i++) {
				second_result_code[i] = '0';
			}
		}
		else {
			for (; i < length1 - length2; i++) {
				second_result_code[i] = '1';
			}
		}
		if (i > 0) {
			for (int t = 0; t < length1; t++) {
				second_result_code[i + t] = change[t];
				if (t + 1 == length1) second_result_code[i + 1 + t] = '\0';
			}
		}
		second_result_code[0] = save;
	}
}

void sum(char* result_code, char* first_result_code, char* second_result_code) { // O(n)
	int n = 0;
	for (; ;n++) {
		if (first_result_code[n] == '\0') break;
	}
	result_code[n + 1] = '\0';
	for (int i = 0; i < n + 1; i++) result_code[i] = '0';

	for (int i = n; i > 1; i--) {
		result_code[i] = ((int)first_result_code[i - 1] - '0') + ((int)second_result_code[i - 1] - '0') + '0';
	}
	for (int i = n; i > 1; i--) {
		if (result_code[i] >= '2') {
			result_code[i] -= 2;
			result_code[i - 1] += 1;
		}
	}
}

// заполнение нулями
void opposite(char* result_code) { // O(n)
	for (int i = 0; result_code[i] != '\0'; i++) {
		if (result_code[i] == '0') result_code[i] = '1';
		else result_code[i] = '0';
	}
}

void operation(char* result_code) { // O(n)
	for (int i = 0; result_code[i] != '\0'; i++) {
		if (result_code[i] == '0') result_code[i] = '1';
		else result_code[i] = '0';
	}
}

// преобразовывает из обратного кода в дополнительный
void change_plus(char* result_code) { // O(n)
	if (result_code[0] == '1') {
		long long n = strlen(result_code);
		result_code[n - 1] += 1;
		for (int i = n - 1; i > 0; i--) {
			if (result_code[i] >= '2') {
				result_code[i - 1] += 1;
				result_code[i] -= 2;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр\nГруппа 353502\nУсловие задания:Перевести числа из обратного кода в естественную форму\n";
	int continuation = 1;
	while (continuation == 1) {
		char first_number[SIZE], second_number[SIZE];
		long long first_value, second_value;
		char first_right_code[SIZE], second_right_code[SIZE];
		char first_result_code[SIZE], second_result_code[SIZE];
		do {
			std::cout << "Введите целочисленное значение первого числа в естественной форме:";
			input_int(first_number);
		} while (check_input_int(first_number) == 0);

		do {
			std::cout << "Введите целочисленное значение второго числа в естественной форме:";
			input_int(second_number);
		} while (check_input_int(second_number) == 0);

		first_value = atoi(first_number);
		second_value = atoi(second_number);

		std::cout << '\n';
		from_norm_to_right_code(first_value, first_right_code, SIZE);
		from_norm_to_right_code(second_value, second_right_code, SIZE);
		std::cout << "Первое число в прямом коде = ";
		conclution(first_right_code);
		std::cout << "Второе число в прямом коде = ";
		conclution(second_right_code);
		std::cout << '\n';
		from_right_to_result_code(first_right_code, first_result_code, SIZE);
		from_right_to_result_code(second_right_code, second_result_code, SIZE);
		change_plus(first_result_code);
		change_plus(second_result_code);
		std::cout << "Первое число в обратном коде = ";
		conclution(first_result_code);
		std::cout << "Второе число в обратном коде = ";
		conclution(second_result_code);
		std::cout << '\n';
		change_for_addition(first_result_code, second_result_code);
		change_for_addition(second_result_code, first_result_code);
		std::cout << "Преобразованное первое число в обратном коде = ";
		conclution(first_result_code);
		std::cout << "Преобразованное второе число в обратном коде = ";
		conclution(second_result_code);
		std::cout << '\n';

		char result_code[SIZE];

		bool first_condition = first_value >= 0, second_condition = second_value >= 0;
		if (first_condition && second_condition) {
			sum(result_code, first_result_code, second_result_code);
		}
		else if ((first_condition && abs(first_value) > abs(second_value)) || (second_condition && abs(second_value) > abs(first_value))) {
			sum(result_code, first_result_code, second_result_code);
			result_code[1] = 'M';
		}
		else if ((first_condition && abs(first_value) < abs(second_value)) || (second_condition && abs(second_value) < abs(first_value))) {
			sum(result_code, first_result_code, second_result_code);
			operation(result_code);
		}
		else {
			operation(first_result_code);
			operation(second_result_code);
			sum(result_code, first_result_code, second_result_code);
			operation(result_code);
		}
		std::cout << "Значение суммы двух чисел в обратном коде равно = ";
		conclution(result_code);
		change_plus(result_code);
		std::cout << "Значение суммы двух чисел в дополнительном коде равно = ";
		conclution(result_code);
		std::cout << '\n' << "Хотите проделать операцию ещё раз?(1 - да, 2 - нет)\n";
		std::cout << "Введите продолжение:";
		std::cin >> continuation;
		std::cout << "\n\n";
	}
	std::cout << "Спасибо за внимание!!!";
}

/*
* tests
* 100, -25 -> 01001010
* 5, -10   -> 11111010
*/