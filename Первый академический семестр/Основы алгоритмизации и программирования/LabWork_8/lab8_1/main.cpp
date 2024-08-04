#include <iostream>
#include <string>
#include "../input_check/input_check.h"
#include "../sortlibrary/sort_library.h"
#include "book.h"

int main() {
	setlocale(LC_ALL, "ru");

	printf("Задание выполнил студент группы 353502, Федорако Александр.\n");
	printf("Вариант выполнения задания:8.\n\n\n");

	printf("Введите первоначальное количество книг в библиотеке:");
	std::string line;
	int size = check_input_int(line);

	int now_change_value = 0;


	Book* book = new Book[size];

	printf("\nВыберите дальнейшее действие\n");
	printf("1.Ввести полною информацию об каждой из книг\n");
	printf("2.Ввести информацию об книгах до определенного признака\n");
	printf("\nВведите продолжение:");

	int next_step = check_input_int_one_or_two(line);
	switch (next_step) {
	case 1:
		input_data_at_start(book, size, now_change_value);
		break;
	case 2:
		printf("\nВыберите дальнейшее действие\n");
		printf("1.Ввести признак, основанный на регистрационном номере\n2.Ввести признак, основанный на имени писателя\n3.Ввести признак, основанный на названии книги\n4.Ввести признак, основанный на годе издания данной книги\n5.Ввести признак, основанный на издании, издавшее данную книги\n6.Ввести признак, основанный на количестве страниц в данной книге\n\nВведите продолжение:");
		std::string number_of_book_characteristic_string;
		int number_of_book_characteristic = check_input_up_to_six(number_of_book_characteristic_string);
		std::string book_characteristic;
		printf("Введите значение, основываясь на которое будет происходить завершение ввода данных библиотеки:");
		std::getline(std::cin, book_characteristic);
		input_to_sign(book, size, now_change_value, number_of_book_characteristic, book_characteristic);
		break;
	}

	int action;
	do {
		printf("\n\nВведите 1, если хотите совершить операции над цехами, 2 в ином случаи:");
		action = check_input_int_one_or_two(line);
		if (action == 1) {
			printf("\nВыберите дальнейшее изменение в данных библиотеки.\n");
			printf("1.Вывести полную информацию об книгах в библиотеке\n");
			printf("2.Дополнить библиотеку значениями новой книги\n");
			printf("3.Вывод информации о книге, имеющей определенное значение\n");
			printf("4.Удаления определенной книги из библиотеки\n");
			printf("5.Отсортировать массив по одной из характеристик\n");
			printf("6.Вернуться к исходному полю\n\n");
			printf("\nВведите продолжение:");
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
	printf("\n\nСпасибо за внимание!");
}

