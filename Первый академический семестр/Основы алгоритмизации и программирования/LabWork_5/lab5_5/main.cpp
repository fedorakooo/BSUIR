#include<iostream>

void conclusion(long long** mass, long long n) {
	std::cout << '\n';
	for (long long k = 0; k < n; k++) {
		for (long long i = 0; i < n; i++) {
			std::cout << mass[k][i] << '\t';
		}
		std::cout << '\n';
	}
}
double average(long long** mass, long long n) {
	double result = 0;
	for (long long k = 0; k < n; k++) {
		for (long long i = 0; i < n; i++) {
			result += mass[k][i];
		}
	}
	result /= n * n;
	return result;
}

int input_check() {
	bool is_correct = true;
	do {
		is_correct = true;
		char* str = new char[100];
		std::cin.getline(str, sizeof(str));
		int n = strlen(str);
		for (int i = 0; i < n; i++) {
			if (!isdigit(str[i])) {
				std::cout << "Некоректный ввод в символе номер " << i + 1 << '\n';
				is_correct = false;
			}
		}
		if (is_correct) {
			for (int i = 0; i < n; i++) {
				return std::atoi(str);
			}
			delete[] str;
		}
		else {
			std::cout << "Пожалуйста повторите попытку\n";
			delete[] str;
		}
	} while (not is_correct);
}

int main() {
	long long start;
	setlocale(LC_ALL, "ru");
	std::cout << "Условие задачи:\nДан двумерный динамический массив целых чисел. Значения элементов данного массива ввести с клавиатуры.Создать динамический массив из элементов, расположенных в четных столбцах данного массива и имеющих нечетное значение.Вычислить среднее арифметическое элементов динамического массива.Вывести результат на экран.";
	do {
		std::cout << "\n\nВведите размерность матрицы:";
		long long n;
		std::cin >> n;
		long long** mass = new long long* [n];
		for (long long i = 0; i < n; i++) {
			mass[i] = new long long[n];
		}
		long long number;
		std::cout << "\n1.Заполнить массив случайными числами.\n2.Заполнить массив числами, вводимыми в ручную.\nВведите вариант продолжения:";
		number = input_check();
		if (t == 1) {
			for (long long k = 0; k < n; k++) {
				for (long long i = 0; i < n; i++) {
					mass[k][i] = rand() % 10;
				}
			}
			conclusion(mass, n);

			std::cout << "\nСреднее значение равно всех элементов массива:" << average(mass, n);
		}
		else {
			for (long long k = 0; k < n; k++) {
				for (long long i = 0; i < n; i++) {
					std::cin >> mass[k][i];
				}
			}
			conclusion(mass, n);
			std::cout << "\nСреднее значение равно всех элементов массива:" << average(mass, n);
		}
		for (long long i = 0; i < n; i++) {
			delete[] mass[i];
		}
		delete[] mass;
		std::cout << "\n\n1.Произвести выполнение программы заново\n2.Завершить выполнение программы\nВведите вариант продолжения:";
		start = input_check();
	} while (start != 2);
}