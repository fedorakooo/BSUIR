#include <iostream>
#include "../staticlib/staticlib.h"

int index(char change) { // O(1) 
	if (change >= '0' && change <= '9')
		return change - '0';
	return 10 + change - 'A';
}

char change(int num) { // O(1)
	if (num < 10)
		return '0' + num;
	return 'A' + (num - 10);
}

std::string sum(std::string s1, std::string s2, int r) { // O(n)
	if (s1.size() < s2.size()) swap(s1, s2);
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	while (s2.size() < s1.size()) s2 += '0';
	int number = 0;
	std::string result = "";
	for (int i = 0; i < s1.size(); i++) {
		int value = index(s1[i]) + index(s2[i]) + p;
		result += change(value % r);
		number = value / r;
	}
	if (number > 0) result += change(p);
	reverse(result.begin(), result.end());
	return result;
}

std::string difference(std::string s1, std::string s2, int r) { // O(n)
	bool minus = false;
	if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2)) {
		minus = true;
		swap(s1, s2);
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	while (s2.size() < s1.size()) s2 += '0';
	int p = 0;
	std::string result = "";
	for (int i = 0; i < s1.size(); i++) {
		int s = index(s1[i]) - index(s2[i]) - p;
		if (s < 0) {
			p = 1;
			s += r;
		}
		result += change(s);
	}
	reverse(result.begin(), result.end());
	return result;
}

std::string to_string(int x1, int n) { // O(1)
	std::string number = "";
	char mass[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	while (x1) {
		int k = x1 % n;
		number += mass[k];
		x1 /= n;
	}
	reverse(number.begin(), number.end());
	return number;
}

long long to_number(std::string number, int n) { // O(n)
	long long result = 0;
	long long k = number.size();
	for (int i = 0; i < k - 1; i++) {
		result += pow(n, i) * (index(number[k - i - 1]) - '0');
	}
	return result;
} 


int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр\nГруппа 353502\nУсловие задания:Перевести числа из обратного кода в естественную форму\n";
	int continuation = 1;
	while (continuation == 1) {
		long long x1, x2;

		char first[100], second[100];
		do {
			std::cout << "Введите целочисленное значение первого числа в естественной форме:";
			input_int(first);
		} while (check_input_int(first) == 0);

		do {
			std::cout << "Введите целочисленное значение второго числа в естественной форме:";
			input_int(second);
		} while (check_input_int(second) == 0);

		x1 = atoi(first);
		x2 = atoi(second);

		int n;
		std::cout << '\n';
		do {
			std::cout << "Введите основание системы счисления:";
			std::cin >> n;
		} while (n > 16 || n <= 0);
		std::string first_number, second_number;
		std::string number;
		if (x1 >= 0 && x2 >= 0) {
			first_number = to_string(x1, n);
			second_number = to_string(x2, n);
			number = sum(first_number, second_number, n);
		}
		else if (x1 <= 0 && x2 <= 0) {
			x1 *= -1;
			x2 *= -1;
			first_number = to_string(x1, n);
			second_number = to_string(x2, n);
			number = '-' + sum(first_number, second_number, n);
		}
		else if (((x1 >= 0 && x2 <= 0) && abs(x1) >= abs(x2)) || ((x2 >= 0 && x1 <= 0) && abs(x2) >= abs(x1))) {
			x2 *= -1;
			first_number = to_string(x1, n);
			second_number = to_string(x2, n);
			number = difference(first_number, second_number, n);
		}
		else {
			x1 *= -1;
			first_number = to_string(x1, n);
			second_number = to_string(x2, n);
			number = '-' + difference(first_number, second_number, n);
		}
		std::cout << '\n' << number;

		std::cout << '\n' << "Хотите проделать операцию ещё раз?(1 - да, 2 - нет)\n";
		std::cout << "Введите продолжение:";
		std::cin >> continuation;
		std::cout << "\n\n";
	}
	std::cout << "Спасибо за внимание!!!";
}