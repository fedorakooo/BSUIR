#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "������� �������� �������� ��������� �����������\n�������� ������ 353502\n������� ���������� �������:8\n";
	std::cout << "������� ������:����� ����������� ����� ���������, ������� ���� ������� ��������� ���������� �������.\n";
	while (true) {
		int a;
		int const size = 40;
		std::cout << "������� ������ ���������� �������:";
		while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "������������ ����" << "\n";
			std::cout << "�������� ������� ������ ���������� �������:";
		}
		int matr[size][size];
		for (int n = 0; n < a; n++) {
			int k = 0;
			for (; k < a; k++) {
				std::cout << "������� ������� ������� � ��������� " << n << ' ' << k << ':';
				while (!(std::cin >> matr[n][k]) || (std::cin.peek() != '\n'))
				{
					std::cin.clear();
					while (std::cin.get() != '\n');
					std::cout << "������������ ����" << "\n";
					std::cout << "�������� ������� ������� ������� � ��������� " << n << ' ' << k << ':';
				}
			}
		}
		std::cout << "�������� ������� ����� ���\n";
		for (int n = 0; n < a; n++) {
			for (int k = 0; k < a; k++) {
				std::cout << matr[n][k] << '\t';
			}
			std::cout << '\n';
		}
		int minim = matr[0][1];
		for (int n = 0; n < a; n++) {
			for (int k = n + 1; k < a; k++) {
				minim = std::min(minim, matr[n][k]);
			}
		}
		std::cout << "\n����������� ������� ������� ���� ������� ��������� �����:" << minim << "\n\n";
	}
}