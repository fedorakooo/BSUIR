#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\nВариант выполнения задания:8\n";
	std::cout << "Условие задачи:Найти минимальный среди элементов, лежащих выше главной диагонали квадратной матрицы.\n";
	while (true) {
		int a;
		int const size = 40;
		std::cout << "Введите размер квадратной матрицы:";
		while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Некорректный ввод" << "\n";
			std::cout << "Повторно введите размер квадратной матрицы:";
		}
		int matr[size][size];
		for (int n = 0; n < a; n++) {
			int k = 0;
			for (; k < a; k++) {
				std::cout << "Введите элемент матрицы с индексами " << n << ' ' << k << ':';
				while (!(std::cin >> matr[n][k]) || (std::cin.peek() != '\n'))
				{
					std::cin.clear();
					while (std::cin.get() != '\n');
					std::cout << "Некорректный ввод" << "\n";
					std::cout << "Повторно введите элемент матрицы с индексами " << n << ' ' << k << ':';
				}
			}
		}
		std::cout << "Исходная матрица имеет вид\n";
		for (int n = 0; n < a; n++) {
			for (int k = 0; k < a; k++) {
				std::cout << matr[n][k] << '\t';
			}
			std::cout << '\n';
		}
		int minim = matr[0][1];
		for (int n = 0; n < a; n++) {
			for (int k = n + 1; k < a; k++) {
				minim = std::min(minim, matr[n][k]);
			}
		}
		std::cout << "\nМинимальный элемент лежащий выше главной диагонали равен:" << minim << "\n\n";
	}
}