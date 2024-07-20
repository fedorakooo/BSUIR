#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\n";

	while (true) {
		int p, a, k = 0, r;
		bool mass[10] = {};
		std::string number;
		std::cin >> number;
		std::cin >> p;
		r = number[p - 1];
		int size = number.length();
		for (int i = 0; i < size; i++) {
			if (number[i] >= '0' && number[i] <= '9')  {
				mass[number[i] - '0'] = 1;
			}
		}
		for (int i = 0; i < 10; i++) {
			k += mass[i];
		}
		std::cout << k << std::endl;
		for (int p = size; p > 0; p--) {
			if (number[p] == r) {
				std::cout << size - p - 1 << " ";
			}
		}
	}
}