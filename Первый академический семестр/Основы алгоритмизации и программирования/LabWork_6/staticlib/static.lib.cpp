#include <iostream>
#include <cmath>
#include <iomanip>

bool input_check_int(char* mass) {
	for (int i = 0; mass[i] != '\0'; i++) {
		if (!(isdigit(mass[i]) || (int)mass[i] == 46)) return 0;
	}
	return 1;
}

bool input_check_double(char* mass) {
	for (int i = 0; mass[i] != '\0'; i++) {
		if (!(isdigit(mass[i]) || (int)mass[i] == 46)) return 0;
	}
	return 1;
}

bool input_check_letters(char* mass) {
	for (int i = 0; mass[i] != '\0'; i++) {
		if (!(isalpha(mass[i]) || ((int)mass[i] <= 32 && (int)mass[i] <= 34) || ((int)mass[i] >= 44 && (int)mass[i] <= 46) || (int)mass[i] == 58 || (int)mass[i] == 59 || (int)mass[i] == 63)) return 0;
	}
	return 1;
}

void cin_str_letters_for_second_exercise(char* text, int SIZE) {
	do {
		std::cout << "¬ведите строку:";
		char a;
		for (int i = 0; i < SIZE; i++) {
			a = getchar();
			if (a == '\n' && i == 0) {
				i--;
				continue;
			}
			text[i] = a;
			if (text[i] == '\n' && i > 0) {
				text[i] = ' ';
				text[i + 1] = '\0';
				break;
			}
		}
	} while (!(input_check_letters(text)));
}

void cin_str_double(char* mass, int SIZE) {
	do {
		std::cout << "¬ведите строку:";
		for (int i = 0; i < SIZE; i++) {
			char a = getchar();
			if (i == 0 && a =='\n') {
				i--;
				continue; 
			}
			if (a == '-') {
				mass[i] = a;
			}
			else {
				mass[i] = a;
				if (mass[i] == '\n' && i > 0) {
					mass[i] = '\0';
					break;
				}
			}
		}
	} while (!(input_check_double(mass + 1)));
}