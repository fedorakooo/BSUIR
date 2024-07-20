#include <iostream>

int main() {

	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\n";

	while (true) {
		long long int a;
		std::cin >> a;
		int const size = 25;
		if (a == 0 || a == 1) {
			std::cout << 1;
			return 0;
		}
		unsigned long long int mass[size] = {};
		unsigned long long int massA[size] = {};
		for (long long int i = 0, a1 = a; a1 != 0; i++) {
			massA[i] += a1 % 10;
			a1 /= 10;
		}
		long long int s = size - 1;
		unsigned long long int massAminus[size] = {};
		for (long long int i = 0, a1 = a - 1; a1 != 0; i++) {
			massAminus[i] += a1 % 10;
			a1 /= 10;
		}
		if (a % 2 == 0) {
			unsigned long long int massA2[size] = {};
			for (long long int i = 0, a1 = 0.5 * a; a1 != 0; i++) {
				massA2[i] += a1 % 10;
				a1 /= 10;
			}
			for (long long int i = 0; i < size - 1; i++) {
				for (int k = 0; k < size - 1; k++) {
					if (massAminus != 0 && massA2[i] != 0) {
						mass[i + k] += massA2[i] * massAminus[k];
					}
				}
			}
			mass[0] += 1;
			for (int i = 0; i < size - 1; i++) {
				if (mass[i] >= 10) {
					mass[i + 1] += mass[i] / 10;
					mass[i] = mass[i] % 10;
				}
			}
		}
		else {
			unsigned long long int massR[size] = {};
			massR[0] = (a - 1) / 2;
			for (long long int i = 0; i < size - 1; i++) {
				if (massR[i] >= 10) {
					massR[i + 1] += massR[i] / 10;
					massR[i] = massR[i] % 10;
				}
			}
			for (long long int i = 0; i < size - 1; i++) {
				for (int k = 0; k < size - 1; k++) {
					if (massA[k] != 0 && massR[i] != 0) {
						mass[i + k] += massA[k] * massR[i];
					}
				}
			}
			mass[0]++;
			for (int i = 0; i < size - 1; i++) {
				if (mass[i] >= 10) {
					mass[i + 1] += mass[i] / 10;
					mass[i] = mass[i] % 10;
				}
			}
		}
		for (; mass[s] == 0; s--);
		for (long long int i = s; i >= 0; i--) {
			std::cout << mass[i];
		}
		std::cout << std::endl;
		for (int i = size - 1; i >= 0; i--) {
			std::cout << mass[i] << ' ';
		}
	}
}