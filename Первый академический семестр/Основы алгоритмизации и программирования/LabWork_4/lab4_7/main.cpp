#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\n";
	while (true) {
		int mass[100] = {};
		int n = 0;
		for (;std::cin >> mass[n]; n++) {

		}
		int maxX = mass[0], minX = mass[0], imax = 0, imin = 0;
		for (int i = 0; i < n; i++) {
			if (mass[i] > maxX) {
				maxX = mass[i];
				imax = i;
			}
		}
		for (int i = 0; i < n; i++) {
			if (mass[i] < minX) {
				minX = mass[i];
				imin = i;
			}
		}
		int i1, i2;
		i1 = std::min(imin, imax) + 1, i2 = std::max(imin, imax);
		for (;i1 < i2; i1++) {
			if (mass[i1] != minX && mass[i1] != maxX)
				mass[i1] = 0;
		}
		int k1 = 0, k2 = 0;
		for (int i = 0; i < n; i++) {
			if (mass[i] == 0) k1++;
			else k2++;
		}
		if (k1 > k2) {
			for (int i = 0; i < n; i++) {
				if (mass[i] != 0) {
					std::cout << mass[i] << ' ';
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				std::cout << mass[i] << ' ';
			}
		}
	}
}