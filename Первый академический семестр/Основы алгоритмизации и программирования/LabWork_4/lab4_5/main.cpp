#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\n";

	while (true) {
		long long x, y;
		std::cin >> y >> x;
		long long matr[40][40] = {};
		long long r;
		for (long long y1 = 0; y1 < y; y1++) {
			for (long long x1 = 0; x1 < x; x1++) {
				std::cin >> r;
				matr[x1][y1] = r;
			}
		}
		matr[0][1] = (matr[0][0] > matr[0][1]) ? matr[0][0] : matr[0][1];
		matr[1][0] = (matr[1][0] > matr[0][0]) ? matr[1][0] : matr[0][0];
		for (long long y1 = 1; y1 < y; y1++) {
			for (long long x1 = 1; x1 < x; x1++) {
				matr[x1][y1] = (matr[x1 - 1][y1] > matr[x1][y1]) ? matr[x1 - 1][y1] : matr[x1][y1];
				matr[x1][y1] = (matr[x1][y1 - 1] > matr[x1][y1]) ? matr[x1][y1 - 1] : matr[x1][y1];
				matr[x1][y1] = (matr[x1 - 1][y1 - 1] > matr[x1][y1]) ? matr[x1 - 1][y1 - 1] : matr[x1][y1];
			}
		}
		for (int y1 = 1, x1 = 0; y1 < y; y1++) {
			matr[x1][y1] = matr[x1][y1 - 1] > matr[x1][y1] ? matr[x1][y1 - 1] : matr[x1][y1];
		}
		for (int x1 = 1, y1 = 0; x1 < x; x1++) {
			matr[x1][y1] = matr[x1 - 1][y1] > matr[x1][y1] ? matr[x1 - 1][y1] : matr[x1][y1];
		}
		if (x <= 2 && y <= 2) {
			matr[0][1] = (matr[0][1] < matr[0][0]) ? matr[0][0] : matr[0][1];
			matr[1][0] = (matr[1][0] < matr[0][0]) ? matr[0][0] : matr[1][0];
		}
		else if (x >= 2 && y >= 2) {
			matr[0][y - 1] = (matr[0][y - 1] < matr[0][y - 2]) ? matr[0][y - 2] : matr[0][y - 1];
			matr[x - 1][0] = (matr[x - 1][0] < matr[x - 2][0]) ? matr[x - 2][0] : matr[x - 1][0];
		}
		else if (x <= 2) {
			matr[0][y - 1] = (matr[0][y - 1] < matr[0][y - 2]) ? matr[0][y - 2] : matr[0][y - 1];
			matr[1][0] = (matr[1][0] < matr[0][0]) ? matr[0][0] : matr[1][0];
		}
		else if (y <= 2) {
			matr[0][1] = (matr[0][1] < matr[0][0]) ? matr[0][0] : matr[0][1];
			matr[x - 1][0] = (matr[x - 1][0] < matr[x - 2][0]) ? matr[x - 2][0] : matr[x - 1][0];
		}
		for (long long y1 = 0; y1 < y; y1++) {
			for (long long x1 = 0; x1 < x; x1++) {
				std::cout << matr[x1][y1] << ' ';
			}
			std::cout << std::endl;
		}
	}
}