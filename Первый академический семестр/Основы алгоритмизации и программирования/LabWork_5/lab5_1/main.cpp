#include <iostream> 
#include "..\staticlib\staticlib.h"

int main() {
	int start;
	setlocale(LC_ALL, "ru");
	std::cout << "������� �������� �������� ��������� �����������\n�������� ������ 353502\n";
	std::cout << "��������� ��������� ��� ���������� ����������� �������� ������� ������������� ������� S = (S1, S2, ..., Sm), ��� ������ ������� Sj ��������� �� ������� : Sj = ? aij ni = 1, j = 1, 2, ..., m; ������������ �������.����������� �������� ������ � ����������.�������� ��������� aij ���������� ������������� ������� - �������";
	do {
		std::cout << "\n\n������� ����������� �������:";
		int n;
		n = input_check();
		int* mass = new int[n];
		int** matr = new int* [n];
		for (int i = 0; i < n; i++) {
			matr[i] = new int[n];
		}

		long long t;
		std::cout << "\n1.��������� ������ ���������� �������.\n2.��������� ������ �������, ��������� � ������.\n������� ������� �����������:";
		t = input_check();

		if (t == 1) {
			randmatr(matr, n);

			second_conclusion(matr, n);

			null(mass, n);

			summass(mass, matr, n);

			int minimum = mass[0], minimumI = 0;
			for (int i = 1; i < n; i++) {
				minimumI = minimI(mass, minimum, i, minimumI);
				minimum = minim(minimum, mass[i]);
			}

			first_conclusion(mass, n);

			conclusion(minimumI, minimum);
		}

		else {
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					std::cout << "������� �������� �������� � ������������ " << k << ' ' << i << " :";
					std::cin >> matr[k][i];
				}
			}
			second_conclusion(matr, n);
			null(mass, n);
			summass(mass, matr, n);
			int minimum = mass[0], minimumI = 0;
			for (int i = 1; i < n; i++) {
				minimumI = minimI(mass, minimum, i, minimumI);
				minimum = minim(minimum, mass[i]);
			}
			first_conclusion(mass, n);
			conclusion(minimumI, minimum);
		}
		for (long long i = 0; i < n; i++) {
			delete[] matr[i];
		}
		delete[] matr;
		delete[] mass;
		std::cout << "\n\n1.���������� ���������� ��������� ������\n2.��������� ���������� ���������\n������� ������� �����������:";
		start = input_check();
	} while (start != 2);
}