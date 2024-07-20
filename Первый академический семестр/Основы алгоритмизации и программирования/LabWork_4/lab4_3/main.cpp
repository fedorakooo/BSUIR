#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\nВариант выполнения задания:8\n";
	std::cout << "Условие задачи:Определить, является ли заданная квадратная матрица ортонормированной, т.е. матрицой, в которой скалярное произведение каждой пары различных строк равно 0, а произведение каждой строки на себя равно 1.\n";
	while (true) {
		int n;
		std::cout << "Введите размер квадратной матрицы:";
		while (!(std::cin >> n) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Некорректный ввод" << "\n";
			std::cout << "Повторно введите размер квадратной матрицы:";
		}
		int** mass = (int**)malloc(n * sizeof(int**));
		for (int i = 0; i < n; i++) {
			mass[i] = (int*)malloc(n * sizeof(int*));
		}
		for (int k = 0; k < n; k++) {
			for (int r = 0; r < n; r++) {
				mass[k][r] = 0;
			}
		}
		int result = 0;
		for (int k = 0; k < n; k++) {
			for (int r = 0; r < n; r++) {
				std::cout << "Введите элемент матрицы с индексами " << k << ' ' << r << ':';
				while (!(std::cin >> mass[k][r]) || (std::cin.peek() != '\n')) {
					std::cin.clear();
					while (std::cin.get() != '\n');
					std::cout << "Некорректный ввод" << "\n";
					std::cout << "Повторно введите элемент матрицы с индексами " << k << ' ' << r << ':';
				}
			}
		}
		std::cout << "\nМатрица принимает вид\n";
		for (int k = 0; k < n; k++) {
			for (int r = 0; r < n; r++) {
				std::cout << mass[k][r] << '\t';
			}
			std::cout << '\n';
		}
		int result1 = 0, result2 = 1;
		int k = 0, f = 0, r =0;
		for (; k < n && result1 == 0 && result2 == 1; k++) {
			result1 = 0, result2 = 0, f = 0, r = 0;
			for (; f < n; f++) {
				if (f != k) {
					for (int t = 0; t < n; t++) {
						result1 += mass[k][t] * mass[f][t];
					}
				}
			}
			for (; r < n; r++) {
				result2 += std::pow(mass[k][r], 2);
			}
		}
		if (f == n && k == n && r == n) {
			std::cout << "\nДанная матрица является ортонормированной\n\n";
		}
		else std::cout << "\nДанная матрица не является ортонормированной\n\n";
		for (int i = 0; i < n; i++) {
			free (mass[i]);
		}
		free(mass);
	}
}