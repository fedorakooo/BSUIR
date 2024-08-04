#include<iostream>

int minim(int a, int b) {
	if (a < b) return a;
	else return b;
}

int minimI(int* mass, int minimum, int i1, int minimumI) {
	return minimum >= mass[i1] ? i1 : minimumI;
}

void null(int* mass, int n) {
	for (int i = 0; i < n; i++) {
		mass[i] = 0;
	}
}

void summass(int* mass, int** matr, int n) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			mass[i] += matr[i][k];
		}
	}
}

void randmatr(int** matr, int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			matr[k][i] = rand() % 100 + 1;
		}
	}
}

void first_conclusion(int* mass, int n) {
	std::cout << "\nОдномерный динамический массив имеет вид:";
	for (long long i = 0; i < n; i++) {
		std::cout << mass[i] << '\t';
	}
	std::cout << '\n';
}

void second_conclusion(int** mass, int n) {
	std::cout << '\n';
	for (long long k = 0; k < n; k++) {
		for (long long i = 0; i < n; i++) {
			std::cout << mass[k][i] << '\t';
		}
		std::cout << '\n';
	}
}

void conclusion(int minimumI, int minimum) {
	std::cout << "\nМинимальное значение присуще элементу матрицы под номером:";
	std::cout << minimumI;
	std::cout << "\nЗначение минимального элемента матрицы:";
	std::cout << minimum;
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
			for (int i = 0; i < n;i++) {
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