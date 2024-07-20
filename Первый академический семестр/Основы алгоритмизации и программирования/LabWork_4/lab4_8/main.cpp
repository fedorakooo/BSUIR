#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\n";
	while (true) {
		int a1, a2;
		std::cin >> a1;
		int a = a1;
		const int SIZE = 20;
		int matr1[SIZE][SIZE] = {};
		int matr2[SIZE][SIZE] = {};
		int x1, x2;
		for (int n = 0; n < a1; n++) {
			for (int k = 0; k < a1; k++) {
				std::cin >> x1;
				matr1[k][n] = x1;
			}
		}
		std::cin >> a2;
		for (int n = 0; n < a2; n++) {
			for (int k = 0; k < a2; k++) {
				std::cin >> x2;
				matr2[k][n] = x2;
			}
		}
		int matr[SIZE][SIZE] = {};
		for (int n = 0; n < a; n++) {
			for (int k = 0; k < a; k++) {
				for (int p = 0;p < a; p++) {
					matr[k][n] += matr1[p][n] * matr2[k][p];
				}
			}
		}

		for (int n = 0; n < a; n++) {
			for (int k = 0; k < a; k++) {
				if (k == a - 1) std::cout << matr[k][n];
				else
					std::cout << matr[k][n] << ' ';
			}
			std::cout << '\n';
		}
	}
}