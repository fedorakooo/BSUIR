#include <iostream>
#include <string>
#include "../input_check/input_check.h"
#include "../sortlibrary/sort_library.h"
#include "book.h"

int main() {
	setlocale(LC_ALL, "ru");

	printf("������� �������� ������� ������ 353502, �������� ���������.\n");
	printf("������� ���������� �������:8.\n\n\n");

	printf("������� �������������� ���������� ���� � ����������:");
	std::string line;
	int size = check_input_int(line);

	int now_change_value = 0;


	Book* book = new Book[size];

	printf("\n�������� ���������� ��������\n");
	printf("1.������ ������ ���������� �� ������ �� ����\n");
	printf("2.������ ���������� �� ������ �� ������������� ��������\n");
	printf("\n������� �����������:");

	int next_step = check_input_int_one_or_two(line);
	switch (next_step) {
	case 1:
		input_data_at_start(book, size, now_change_value);
		break;
	case 2:
		printf("\n�������� ���������� ��������\n");
		printf("1.������ �������, ���������� �� ��������������� ������\n2.������ �������, ���������� �� ����� ��������\n3.������ �������, ���������� �� �������� �����\n4.������ �������, ���������� �� ���� ������� ������ �����\n5.������ �������, ���������� �� �������, �������� ������ �����\n6.������ �������, ���������� �� ���������� ������� � ������ �����\n\n������� �����������:");
		std::string number_of_book_characteristic_string;
		int number_of_book_characteristic = check_input_up_to_six(number_of_book_characteristic_string);
		std::string book_characteristic;
		printf("������� ��������, ����������� �� ������� ����� ����������� ���������� ����� ������ ����������:");
		std::getline(std::cin, book_characteristic);
		input_to_sign(book, size, now_change_value, number_of_book_characteristic, book_characteristic);
		break;
	}

	int action;
	do {
		printf("\n\n������� 1, ���� ������ ��������� �������� ��� ������, 2 � ���� ������:");
		action = check_input_int_one_or_two(line);
		if (action == 1) {
			printf("\n�������� ���������� ��������� � ������ ����������.\n");
			printf("1.������� ������ ���������� �� ������ � ����������\n");
			printf("2.��������� ���������� ���������� ����� �����\n");
			printf("3.����� ���������� � �����, ������� ������������ ��������\n");
			printf("4.�������� ������������ ����� �� ����������\n");
			printf("5.������������� ������ �� ����� �� �������������\n");
			printf("6.��������� � ��������� ����\n\n");
			printf("\n������� �����������:");
			std::string next_step_2_string;
			int next_step_2 = check_input_up_to_six(next_step_2_string);
			switch (next_step_2) {
			case 1:
				output_all_data(book, now_change_value);
				break;
			case 2:
				adding_book(book, size, now_change_value);
				break;
			case 3:
				search_and_output(book, now_change_value);
				break;
			case 4:
				delete_book(book, now_change_value);
				break;
			case 5:
				sort_library_Book_and_output(book, now_change_value);
				break;
			}
		}
	} while (action == 1);
	delete[] book;
	printf("\n\n������� �� ��������!");
}

