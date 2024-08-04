#include <iostream> 
#include <fstream>
#include <string>		
#include "../input_check/input_check.h"
#include "../sortlibrary/sort_library.h"
#include "workshop.h"

int main() {
	setlocale(LC_ALL, "ru");

	//������� ������ ������ ofstream
	std::ofstream input;
	std::ofstream output;

	//�������� ����� open ��� ������ � �������� ������
	input.open("InputData.txt");
	output.open("OutputData.txt");

	//��������� �������� ����� �� ������
	if (!input.is_open() || !output.is_open()) {
		std::cout << "������ �������� �����!\n";
	}
	else {
		std::cout << "������� �������� ������� ������ 353502, �������� ���������.\n";
		std::cout << "������� ���������� �������:8.\n";
		std::cout << "������� �������: ��� ��������� ���� ���������� ������� ���������� ���������� ������� �� ������� ������������ � ������� �������� ����������.\n\n\n";

		std::cout << "������� ����������� ���������� ��������� �����:";
		std::string n_string;
		long long n;
		n = check_input_int(n_string);

		Workshop* workshop = new Workshop[n];

		std::cout << "\n������� ������ ���� �������������� �����\n";
		for (int i = 0; i < n; i++) {
			std::cout << i + 1 << ':';
			std::getline(std::cin, workshop[i].number);
		}

		std::string action_string;
		long long action;
		do {
			std::cout << "\n\n������� 1, ���� ������ ��������� �������� ��� ������, 2 � ���� ������:";
			action = check_input_int_one_or_two(action_string);
			if (action == 1) {
				std::cout << "\n�������� ���������� ��������.\n1.��������� ������������ ��� ��������� ����������\n2.������� �������� ������������� ���� � ������� ����������� ��� ��������������� ��������\n";
				std::cout << "3.�������� ������������ ���\n4.������� ������������ ���\n5.�������� �������� ������������� ����\n6.������� ������ ���������� ���� ����� � ��������������� �������\n\n������� �����������:";
				std::string next_action_string;
				long next_action = check_input_up_to_six(next_action_string);
				switch (next_action) {
				case 1:
					input_data(workshop, n);
					break;
				case 2:
					output_data(workshop, n);
					break;
				case 3:
					adding_workshop(workshop, n);
					break;
				case 4:
					delete_workshop(workshop, n);
					break;
				case 5:
					change_workshop(workshop, n);
					break;
				case 6:
					output_all_data(workshop, n);
					break;
				}
			}
		} while (action == 1);
		output_all_data(workshop, n);

		input << "���������� ��� ���� �����.\n";
		for (int i = 0; i < n; i++) {
			input << "\n������������ ���� ����� " << i + 1 << ':' << workshop[i].number << '\n';
			input << "������������ ���������\t\t���������� ���������\n";
			for (int t = 0; t < workshop[i].size; t++) input << workshop[i].name[t] << "\t\t\t" << workshop[i].quantity[t] << "\n";
			input << "���������� ��������� ���������:" << workshop[i].size << "\n\n";
		}

		output << "��������� ��������.";
		output << "\n";
		for (int i = 0; i < n; i++) {
			long long* intermediate_value = new long long[workshop[i].size];
			for (int k = 0; k < workshop[i].size; k++) {
				intermediate_value[k] = workshop[i].quantity[k];
			}
			for (int k = 0; k < workshop[i].size; k++) {
				selection_sort(intermediate_value, workshop[i].size);
			}
			if (workshop[i].number != "DELETE") {
				output << "������ ��������������� ���������� �� ���� ��� �������:" << workshop[i].number;
				output << "\n������������ ���������\t���������� ���������\n";
				for (int k = 0; k < workshop[i].size; k++) {
					for (int t = 0; t < workshop[i].size; t++) {
						if (intermediate_value[k] == workshop[i].quantity[t] && workshop[i].name[t] != "") {
							if (!(k > 0 && intermediate_value[k - 1] == intermediate_value[k])) output << workshop[i].name[t] << "\t\t\t" << workshop[i].quantity[t] << '\n';
						}
					}
				}
			}
			output << '\n';
			delete[] intermediate_value;
		}
		printf("\n\n������� �� ��������!");
		input.close();
		output.close();
		delete[] workshop;
	}
}


		