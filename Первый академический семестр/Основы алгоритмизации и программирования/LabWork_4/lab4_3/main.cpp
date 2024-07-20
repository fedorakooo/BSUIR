#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "������� �������� �������� ��������� �����������\n�������� ������ 353502\n������� ���������� �������:8\n";
	std::cout << "������� ������:����������, �������� �� �������� ���������� ������� �����������������, �.�. ��������, � ������� ��������� ������������ ������ ���� ��������� ����� ����� 0, � ������������ ������ ������ �� ���� ����� 1.\n";
	while (true) {
		int n;
		std::cout << "������� ������ ���������� �������:";
		while (!(std::cin >> n) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "������������ ����" << "\n";
			std::cout << "�������� ������� ������ ���������� �������:";
		}
		int** mass = (int**)malloc(n * sizeof(int**));
		for (int i = 0; i < n; i++) {
			mass[i] = (int*)malloc(n * sizeof(int*));
		}
		for (int k = 0; k < n; k++) {
			for (int r = 0; r < n; r++) {
				mass[k][r] = 0;
			}
		}
		int result = 0;
		for (int k = 0; k < n; k++) {
			for (int r = 0; r < n; r++) {
				std::cout << "������� ������� ������� � ��������� " << k << ' ' << r << ':';
				while (!(std::cin >> mass[k][r]) || (std::cin.peek() != '\n')) {
					std::cin.clear();
					while (std::cin.get() != '\n');
					std::cout << "������������ ����" << "\n";
					std::cout << "�������� ������� ������� ������� � ��������� " << k << ' ' << r << ':';
				}
			}
		}
		std::cout << "\n������� ��������� ���\n";
		for (int k = 0; k < n; k++) {
			for (int r = 0; r < n; r++) {
				std::cout << mass[k][r] << '\t';
			}
			std::cout << '\n';
		}
		int result1 = 0, result2 = 1;
		int k = 0, f = 0, r =0;
		for (; k < n && result1 == 0 && result2 == 1; k++) {
			result1 = 0, result2 = 0, f = 0, r = 0;
			for (; f < n; f++) {
				if (f != k) {
					for (int t = 0; t < n; t++) {
						result1 += mass[k][t] * mass[f][t];
					}
				}
			}
			for (; r < n; r++) {
				result2 += std::pow(mass[k][r], 2);
			}
		}
		if (f == n && k == n && r == n) {
			std::cout << "\n������ ������� �������� �����������������\n\n";
		}
		else std::cout << "\n������ ������� �� �������� �����������������\n\n";
		for (int i = 0; i < n; i++) {
			free (mass[i]);
		}
		free(mass);
	}
}