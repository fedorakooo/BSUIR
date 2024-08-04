#include <iostream>
#include <string>
#include "../staticlib/staticlib.h"

int powl(long long k, long long n) {
	if (n == 0) return 1;
	else return k * powl(k, n - 1);
}

int main() { // O(n)
	setlocale(LC_ALL, "ru");
	std::cout << "������� �������� �������� ���������\n������ 353502\n������� �������:��������� ����� �� ��������� ���� � ������������ �����\n";
	int continuation = 1;
	while (continuation == 1) {
		std::string return_code;
		do {
			std::cout << "������� ����� � �������� ����� ��� �������� � ������������ �����:";
			std::cin >> return_code;
		} while (check_input_string(return_code) == 0);
		long long result = 0;
		long long size = return_code.length() - 1;
		if (return_code[0] == '0') {
			for (long long i = size; i > 0; i--) {
				if (return_code[i] == '1') result += powl(2, size - i);
			}
		}
		else {
			for (long long i = size; i > 0; i--) { 
				if (return_code[i] == '0') result -= powl(2, size - i);
			}
		}
		std::cout << "����� = " << result;
		std::cout << '\n' << "\n������ ��������� �������� ��� ���?(1 - ��, 2 - ���)\n";
		std::cout << "������� �����������:";
		std::cin >> continuation;
		std::cout << "\n\n";
	}
	std::cout << "������� �� ��������!!!";
}