#include <iostream>
int main() {

	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\n";

	while (true) {
		long n;
		std::cin >> n;
		long a = 1, b = 0;
		for (long i = 0, t = 1;; i = i + 2, t = t + 2) {
			b = a + 2 * i;
			a = b + 2 * t;
			if (n == b) {
				std::cout << i << ' ' << i;
				return 0;
			}
			if (n == a) {
				std::cout << i + 1 << ' ' << i + 1;
				return 0;
			}
			if (n < a && n >= a - i - 1) {
				std::cout << i - (a - n) + 1 << ' ' << i + 1;
				return 0;
			}
			if (n < b && n >= b - i - 1) {
				std::cout << i - (b - n) << ' ' << i;
				return 0;
			}
			if (n > a && n <= a + i + 1) {
				std::cout << i + 1 << ' ' << i - (n - a) + 1;
				return 0;
			}
			if (n > b && n <= b + i + 1) {
				std::cout << i << ' ' << i - (n - b);
				return 0;
			}
		}
	}
}