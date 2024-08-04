#include <iostream>

void second_conclusion(int** mass, int n) {
	std::cout << '\n';
	for (long long k = 0; k < n; k++) {
		for (long long i = 0; i < n; i++) {
			std::cout << mass[k][i] << '\t';
		}
		std::cout << '\n';
	}
}
void randmatr(int** matr, int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			matr[k][i] = rand() % 100 + 1;
		}
	}
}
void revers(int** matr, int** correctmatr, int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			correctmatr[k][i] = matr[n - k - 1][n - i - 1];
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "������� �������� �������� ��������� �����������\n�������� ������ 353502\n";
	int start = 1;
	while (start != 2) {
		int n;
		std::cout << "\n������� ����������� �������:";
		std::cin >> n;

		int** matr = new int* [n];
		for (int i = 0; i < n; i++) {
			matr[i] = new int[n];
		}
		int** correctmatr = new int* [n];
		for (int i = 0; i < n; i++) {
			correctmatr[i] = new int[n];
		}
		long long t;
		std::cout << "\n1.��������� ������ ���������� �������.\n2.��������� ������ �������, ��������� � ������.\n������� ������� �����������:";
		std::cin >> t;
		if (t == 1) {
			randmatr(matr, n);

	     	std::cout << "\n�������� ������� ����� ���";
			second_conclusion(matr, n);

			revers(matr, correctmatr, n);

			std::cout << "\n��������������� ������� ����� ���";
			second_conclusion(correctmatr, n);
		}
		else {
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					std::cin >> matr[k][i];
				}
			}

			std::cout << "\n�������� ������� ����� ���";
			second_conclusion(matr, n);

			revers(matr, correctmatr, n);

			std::cout << "\n��������������� ������� ����� ���";
			second_conclusion(correctmatr, n);
		}

		for (int i = 0; i < n; i++) {
			delete[] matr[i];
		}
		delete[]matr;
		for (int i = 0; i < n; i++) {
			delete[] correctmatr[i];
		}
		delete[] correctmatr;
		std::cout << "\n\n1.���������� ���������� ��������� ������\n2.��������� ���������� ���������\n������� ������� �����������:";
		std::cin >> start;
	}
}