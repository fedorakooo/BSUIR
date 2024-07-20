#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\n";
	const int MAX = 999999999;
	while (true) {
		int a, b;
		std::cin >> a >> b;
		int const size = 50;
		int mass[size][size];
		for (int n = 0; n < size;n++) {
			for (int k = 0; k < size; k++) {
				mass[n][k] = MAX;
			}
		}
		int result = 0;
		int x;
		for (int n = 1; n < a + 1; n++) {
			for (int k = 1; k < b + 1; k++) {
				std::cin >> x;
				mass[n][k] = x;
			}
		}
		for (int n = 1; n < a + 1; n++) {
			for (int k = 1; k < b + 1; k++) {
				int k1 = k + 1, k2 = k - 1, n1 = n + 1, n2 = n - 1;
				if (mass[n][k] < mass[n1][k] && mass[n][k] < mass[n2][k]) {
					if (mass[n][k] < mass[n][k1] && mass[n][k] < mass[n][k2]) {
						result++;
					}
				}
			}
		}
		std::cout << result;
	}
}