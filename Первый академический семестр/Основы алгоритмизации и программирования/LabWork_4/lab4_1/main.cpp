#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	const int SIZE = 1000;
	std::cout << "������� �������� �������� ��������� �����������\n�������� ������ 353502\n������� ���������� �������:8\n";
	std::cout << "������� ������:������ ���������� ����������� ������ �� k ���������. ������� ����������� � ������������ �������� �������.\n\n";
	while (true) {
		std::cout << "������� ������ ��������� �������:";
		int razm;
		while (!(std::cin >> razm) || (std::cin.peek() != '\n') || razm > 1000)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "������������ ����" << "\n";
			std::cout << "�������� ������� ������ ��������� �������:";
		}

		int mass[SIZE] = {};
		for (int i = 0; i < razm; i++) {
			std::cout << "������� ������� ������� � �������� " << i << ':';
			int chislo;
			while (!(std::cin >> chislo) || (std::cin.peek() != '\n'))
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "������������ ����" << "\n";
				std::cout << "�������� ������� ������� ������� � �������� " << i << ':';
			}
			mass[i] = chislo;
		}
		std::cout << "\n�������� ������:";
		for (int i = 0; i < razm; i++) {
			std::cout << mass[i] << '\t';
		}
		std::cout << "\n�������� ������:";
		int maxS = mass[0], minS = mass[0], r1[SIZE] = {}, r2[SIZE] = {};
		for (int i = 0; i < razm; i++) {
			if (mass[i] > maxS) {
				maxS = mass[i];
			}
		}

		for (int i = 0; i < razm; i++) {
			if (mass[i] < minS) {
				minS = mass[i];
			}
		}
		int r = razm;
		for (int i = 0; i < razm; i++) {
			if (mass[i] == minS || mass[i] == maxS) {
				r--;
				continue;
			}
			std::cout << mass[i] << '\t';
		}
		if (r == 0) {
			std::cout << "������ ���;)";
		}
		std::cout << "\n\n";
	}
}