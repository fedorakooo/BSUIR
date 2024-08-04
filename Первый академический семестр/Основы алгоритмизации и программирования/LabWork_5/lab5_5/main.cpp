#include<iostream>

void conclusion(long long** mass, long long n) {
	std::cout << '\n';
	for (long long k = 0; k < n; k++) {
		for (long long i = 0; i < n; i++) {
			std::cout << mass[k][i] << '\t';
		}
		std::cout << '\n';
	}
}
double average(long long** mass, long long n) {
	double result = 0;
	for (long long k = 0; k < n; k++) {
		for (long long i = 0; i < n; i++) {
			result += mass[k][i];
		}
	}
	result /= n * n;
	return result;
}

int input_check() {
	bool is_correct = true;
	do {
		is_correct = true;
		char* str = new char[100];
		std::cin.getline(str, sizeof(str));
		int n = strlen(str);
		for (int i = 0; i < n; i++) {
			if (!isdigit(str[i])) {
				std::cout << "����������� ���� � ������� ����� " << i + 1 << '\n';
				is_correct = false;
			}
		}
		if (is_correct) {
			for (int i = 0; i < n; i++) {
				return std::atoi(str);
			}
			delete[] str;
		}
		else {
			std::cout << "���������� ��������� �������\n";
			delete[] str;
		}
	} while (not is_correct);
}

int main() {
	long long start;
	setlocale(LC_ALL, "ru");
	std::cout << "������� ������:\n��� ��������� ������������ ������ ����� �����. �������� ��������� ������� ������� ������ � ����������.������� ������������ ������ �� ���������, ������������� � ������ �������� ������� ������� � ������� �������� ��������.��������� ������� �������������� ��������� ������������� �������.������� ��������� �� �����.";
	do {
		std::cout << "\n\n������� ����������� �������:";
		long long n;
		std::cin >> n;
		long long** mass = new long long* [n];
		for (long long i = 0; i < n; i++) {
			mass[i] = new long long[n];
		}
		long long number;
		std::cout << "\n1.��������� ������ ���������� �������.\n2.��������� ������ �������, ��������� � ������.\n������� ������� �����������:";
		number = input_check();
		if (t == 1) {
			for (long long k = 0; k < n; k++) {
				for (long long i = 0; i < n; i++) {
					mass[k][i] = rand() % 10;
				}
			}
			conclusion(mass, n);

			std::cout << "\n������� �������� ����� ���� ��������� �������:" << average(mass, n);
		}
		else {
			for (long long k = 0; k < n; k++) {
				for (long long i = 0; i < n; i++) {
					std::cin >> mass[k][i];
				}
			}
			conclusion(mass, n);
			std::cout << "\n������� �������� ����� ���� ��������� �������:" << average(mass, n);
		}
		for (long long i = 0; i < n; i++) {
			delete[] mass[i];
		}
		delete[] mass;
		std::cout << "\n\n1.���������� ���������� ��������� ������\n2.��������� ���������� ���������\n������� ������� �����������:";
		start = input_check();
	} while (start != 2);
}