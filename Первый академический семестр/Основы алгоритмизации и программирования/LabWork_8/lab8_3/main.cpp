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
	
	//��������� �������� ����� �� ������
	if (!input.is_open() || !output.is_open()) {
		std::cout << "������ �������� �����!\n";
	}
	else {
		std::cout << "������� �������� ������� ������ 353502, �������� ���������.\n";
		std::cout << "������� ���������� �������:10.\n";
		std::cout << "\n\n������� ����������� ���������� �����������:";
		std::string size_string;
		int size = check_input_int(size_string);
		Player* player = new Player[size];

		input << "����������� ���������� �����������:" << size << '\n';

		std::cout << "\n������� ����� ���� �����������\n";
		input << "����������� ����� �����������\n";
		for (int i = 0; i < size; i++) {
			std::cout << i + 1 << ':';
			std::getline(std::cin, player[i].name);
			input << player[i].name << '\n';
		}

		std::string action_string;
		long long action;
		do {
			std::cout << "\n\n������� 1, ���� ������ ��������� �������� ��� ��������������� ��� ����� ������ �����������, 2 � ���� ������:";
			action = check_input_int_one_or_two(action_string);
			if (action == 1) {
				std::cout << "\n�������� ���������� ��������.\n1.������ � ���� ������ �������� �� ������������ ����������\n";
				std::cout << "2.�������� ������������� ����������\n3.��������� ������������� ����������\n4.�������� ������ ������������� ����������\n5.������� ������ ������ ����������, � ������ ��������� �������\n6.������� ���������� � ����� ������� �������\n\n������� �����������:";
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

		printf("\n\n������� �� ��������!");

		delete[] player;
	}
}
