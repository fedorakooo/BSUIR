#include <iostream>
#include "../staticlib/staticlib.h"

int const SIZE = 1000;

bool check_for_letter(char a) {
	if ((a >= 97 && a <= 122) || (a >= 65 && a <= 90)) return 1;
	else return 0;
}

bool check_for_space(char a) {
	return a == 32 ? 1 : 0;
}

bool check_for_votels(char a) {
	char letters[] = { 'q', 'w', 'r', 't', 'p', 's', 'd', 'f', 'g', 'h', 'j', 'k','l','z','x', 'c', 'v', 'b', 'n', 'm', '\0' };
	long long size = strlen(letters);
	for (int i = 0; i < size; i++) {
		if (a == letters[i]) return 1;
	}
	return 0;
}

bool check_for_size(int size, char* text, int startcheck) {
	int check = startcheck;
	for (; check < startcheck + size + 1; check++) {
		if (check == startcheck + size && (int)text[check] == 32) return 1;
		else if (check_for_letter(text[check]) != 1) break;
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр\nГруппа 353502\nУсловие задания:Из текста удалить все слова заданной длины, начинающиеся с согласных букв.\n\n\n";
	int continuation = 1;
	while (continuation == 1) {
		std::cout << "Введите проверяемый текст\n";
		char text[SIZE];
		cin_str_letters_for_second_exercise(text, SIZE);
		std::cout << '\n' << "Введите количество букв в слове:";
		int size;
		std::cin >> size;
		int mass_start_word[SIZE] = {};
		int t = 0;
		if (check_for_votels(text[0]) == 1) {
			t++;
		}
		for (int i = 1; text[i] != '\0'; i++) {
			if (check_for_space(text[i - 1]) == 1 && check_for_votels(text[i]) == 1) {
				mass_start_word[t] = i;
				t++;
			}
		}
		for (int p = 0; p <= t; p++) {
			if (check_for_size(size, text, mass_start_word[p]) == 1) {
				for (int i = mass_start_word[p]; i < mass_start_word[p] + size + 1; i++) {
					text[i] = '0';
				}
			}
		}
		for (int i = 0; text[i] != '\0'; i++) {
			if (text[i] != '0') std::cout << text[i];
		}
		std::cout << '\n' << "Хотите проделать операцию ещё раз?(1 - да, 2 - нет)\n";
		std::cout << "Введите продолжение:";
		std::cin >> continuation;
		std::cout << "\n\n";
	}
	std::cout << "Спасибо за внимание!!!";
}