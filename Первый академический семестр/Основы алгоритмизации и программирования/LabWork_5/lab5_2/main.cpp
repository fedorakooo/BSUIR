#include <iostream>
#include <cmath>
#include <windows.h>

int main()
{
	HINSTANCE load;
	load = LoadLibrary(L"dynamiclib.dll");

	typedef bool (*Is_cos_plus) (int*, int, int);
	typedef bool (*Is_mass_cos_plus)(int*, int, int);

	Is_cos_plus is_cos_plus;
	Is_mass_cos_plus is_mass_cos_plus;
		
	is_cos_plus = (Is_cos_plus)GetProcAddress(load, "Is_cos_plus");
	is_mass_cos_plus = (Is_mass_cos_plus)GetProcAddress(load, "Is_mass_cos_plus");

	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\n";
	int start = 1;
	while (start != 2) {
	int n;
	std::cout << "\nВведите количество вводимых значений X:";
	std::cin >> n;
	int* mass = new int[n];
	std::cout << "Введите значения X\n";
	for (int i = 0; i < n; i++) {
		std::cin >> mass[i];
	}
	if (is_mass_cos_plus(mass, 0, n - 1)) std::cout << "\nВсе значения cos(X) больше нуля";
	else std::cout << "\nНе все значения cos(X) больше нуля";

	std::cout << "\n\n1.Произвести выполнение программы заново\n2.Завершить выполнение программы\nВведите вариант продолжения:";
	std::cin >> start;
	}
	FreeLibrary(load);
}
