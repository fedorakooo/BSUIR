#include <iostream>
#include <string>
#include "../staticlib/staticlib.h"

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр\nГруппа 353502\nУсловие задания:В консоль вводится текст на английском языке, без переносов слов. Длина строк не превышает 100 символов.\n\n\n";
	char condition[100];
	do {
		std::string text;
		std::cout << "Введите строку:";
		char a;
		char letters[] = { 'q','w','r','t','p','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m' };
		char mass[sizeof(letters)];
		for (int i = 0; i < sizeof(letters); i++) {
			mass[i] = (int)letters[i] + ((int)'A' - (int)'a');
		}
		getline(std::cin, text);
		for (int r = 0; r < text.size(); r++) {
			for (int i = 0; i < text.size(); i++) {
				if (text[i] == 'c' && (text[i + 1] == 'i' || text[i + 1] == 'e' || text[i + 1] == 'y')) {
					text[i] = 's';
				}

				if (text[i] == 'c') text[i] = 'k';
				else if (text[i] == 'C') text[i] = 'C';

				else if (text[i] == 'q' && text[i + 1] == 'u') {
					text[i] = 'k'; text[i + 1] = 'v'; i++;
				}
				else if (text[i] == 'Q' && text[i + 1] == 'u') {
					text[i] = 'K'; text[i + 1] = 'v'; i++;
				}

				else if (text[i] == 'q') text[i] = 'k';
				else if (text[i] == 'Q') text[i] = 'K';


				else if (text[i] == 'x') {
					std::string change = "ks";
					text.replace(i, 1, change, 0, 2);
				}
				else if (text[i] == 'X') {
					std::string change = "Ks";
					text.replace(i, 1, change, 0, 2);
				}

				else if (text[i] == 'w') text[i] = 'v';
				else if (text[i] == 'W') text[i] = 'V';

				else if (text[i] == 'p' && text[i + 1] == 'h') {
					std::string change = "f";
					text.replace(i, 2, change, 0, 1);
				}
				else if (text[i] == 'P' && text[i + 1] == 'h') {
					std::string change = "F";
					text.replace(i, 2, change, 0, 1);
				}

				else if (text[i] == 'y' && text[i + 1] == 'o' && text[i + 2] == 'u') {
					std::string change = "u";
					text.replace(i, 3, change, 0, 1);
				}
				else if (text[i] == 'Y' && text[i + 1] == 'o' && text[i + 2] == 'u') {
					std::string change = "U";
					text.replace(i, 3, change, 0, 12);
				}

				else if (text[i] == 'o' && text[i + 1] == 'o') {
					std::string change = "u";
					text.replace(i, 2, change, 0, 1);
				}
				else if (text[i] == 'O' && text[i + 1] == 'o') {
					std::string change = "U";
					text.replace(i, 2, change, 0, 1);
				}

				else if (text[i] == 'e' && text[i + 1] == 'e') {
					std::string change = "i";
					text.replace(i, 2, change, 0, 1);
				}
				else if (text[i] == 'E' && text[i + 1] == 'e') {
					std::string change = "I";
					text.replace(i, 2, change, 0, 1);
				}
				else if (text[i] == 't' && text[i + 1] == 'h') {
					std::string change = "z";
					text.replace(i, 2, change, 0, 1);
				}
				else if (text[i] == 'T' && text[i + 1] == 'h') {
					std::string change = "Z";
					text.replace(i, 2, change, 0, 1);
				}

				for (int k = 0; k < sizeof(letters) && i > 0; k++) {
					if (text[i - 1] == letters[k] && text[i] == letters[k]) {
						if (i != 0) {
							text.erase(i, 1);
							i--;
						}
						else text.erase(i, 1);
					}
				}
				for (int k = 0; k < sizeof(mass) && i > 0; k++) {
					if (text[i - 1] == mass[k] && text[i] == letters[k]) {
						if (i != 0) {
							text.erase(i, 1);
							i--;
						}
					}
				}
			}
		}
		std::cout << '\n' << text << '\n';
		std::cout << '\n' << "Хотите проделать операцию ещё раз?(1 - да, 2 - нет)\n";
		do {
			std::cout << "Введите продолжение:";
			for (int i = 0;i < 100;i++) {
				condition[i] = getchar();
				if (condition[i] == '\n' && i > 0) {
					condition[i] = '\0';
					break;
				}
			}
		} while (!(input_check_int(condition) && (condition[0] == '2' || condition[0] == '1')));
		std::cout << "\n\n";
	} while (condition[0] == '1');
	std::cout << "Спасибо за внимание!!!";
}