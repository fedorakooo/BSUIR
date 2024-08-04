 #include <iostream>
#include <string>
#include <fstream>
#include "../input_check/input_check.h"
#include "../sortlibrary/sort_library.h"
#include "player.h"

int main() {
	
	setlocale(LC_ALL, "ru");
	std::ofstream input("InputData.txt", std::ios::app | std::ios::binary);
	std::ofstream output("OutputData.txt", std::ios::app | std::ios::binary);
	
	//проверяем открытие файла на ошибку
	if (!input.is_open() || !output.is_open()) {
		std::cout << "Ошибка открытия файла!\n";
	}
	else {
		std::cout << "Задание выполнил студент группы 353502, Федорако Александр.\n";
		std::cout << "Вариант выполнения задания:10.\n";
		std::cout << "\n\nВведите изначальное количество спортсменов:";
		std::string size_string;
		int size = check_input_int(size_string);
		Player* player = new Player[size];

		input << "Изначальное количество спортсменов:" << size << '\n';

		std::cout << "\nВведите имена всех спортсменов\n";
		input << "Изначальные имена спортсменов\n";
		for (int i = 0; i < size; i++) {
			std::cout << i + 1 << ':';
			std::getline(std::cin, player[i].name);
			input << player[i].name << '\n';
		}

		std::string action_string;
		long long action;
		do {
			std::cout << "\n\nВведите 1, если хотите совершить операции над преобразованием над базой данных спортсменов, 2 в ином случаи:";
			action = check_input_int_one_or_two(action_string);
			if (action == 1) {
				std::cout << "\nВыберите дальнейшее действие.\n1.Ввести в базу данных значение об определенном спортсмене\n";
				std::cout << "2.Добавить определенного спорстмена\n3.Исключить определенного спортсмена\n4.Изменить данные определенного спортсмена\n5.Вывести полный список участников, с точным описанием каждого\n6.Вывести информацию о самой молодой команде\n\nВведите продолжение:";
				std::string next_action_string;
				long next_action = check_input_up_to_six(next_action_string);
				switch (next_action) {
				case 1:
					input_data(player, size, input);
					break;
				case 2:
					adding_Player(player, size, input);
					break;
				case 3:
					delete_player(player, size, input);
					break;
				case 4:
					change_player(player, size, input);
					break;
				case 5:
					output_all_data(player, size);
					break;
				case 6:
					output_some_data(player, size);
					break;
				}
			}
		} while (action == 1);
		output_some_data_end(player, size, output);

		printf("\n\nСпасибо за внимание!");

		delete[] player;
	}
}
