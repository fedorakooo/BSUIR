#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	const int SIZE = 1000;
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\nВариант выполнения задания:8\n";
	std::cout << "Условие задачи:Ввести одномерный статический массив из k элементов. Удалить минимальный и максимальный элементы массива.\n\n";
	while (true) {
		std::cout << "Введите размер исходного массива:";
		int razm;
		while (!(std::cin >> razm) || (std::cin.peek() != '\n') || razm > 1000)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Некорректный ввод" << "\n";
			std::cout << "Повторно введите размер исходного массива:";
		}

		int mass[SIZE] = {};
		for (int i = 0; i < razm; i++) {
			std::cout << "Введите элемент массива с индексом " << i << ':';
			int chislo;
			while (!(std::cin >> chislo) || (std::cin.peek() != '\n'))
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "Некорректный ввод" << "\n";
				std::cout << "Повторно введите элемент массива с индексом " << i << ':';
			}
			mass[i] = chislo;
		}
		std::cout << "\nИсходный массив:";
		for (int i = 0; i < razm; i++) {
			std::cout << mass[i] << '\t';
		}
		std::cout << "\nКонечный массив:";
		int maxS = mass[0], minS = mass[0], r1[SIZE] = {}, r2[SIZE] = {};
		for (int i = 0; i < razm; i++) {
			if (mass[i] > maxS) {
				maxS = mass[i];
			}
		}

		for (int i = 0; i < razm; i++) {
			if (mass[i] < minS) {
				minS = mass[i];
			}
		}
		int r = razm;
		for (int i = 0; i < razm; i++) {
			if (mass[i] == minS || mass[i] == maxS) {
				r--;
				continue;
			}
			std::cout << mass[i] << '\t';
		}
		if (r == 0) {
			std::cout << "Ничего нет;)";
		}
		std::cout << "\n\n";
	}
}