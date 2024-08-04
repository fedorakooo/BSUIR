#include <iostream>
#include <string>
#include "../input_check/input_check.h"
#include "../sortlibrary/sort_library.h"

struct Book {
	std::string registration_number;
	std::string writer;
	std::string name;
	std::string year;
	std::string publisher;
	std::string page;
};

// вводит значение определенной книги
void input_data(Book& book) {
	printf("\nВведите регистрационный номер вводимой книги:");
	std::getline(std::cin, book.registration_number);
	printf("Введите имя писателя данной книги:");
	std::getline(std::cin, book.writer);
	printf("Введите название данной книги:");
	std::getline(std::cin, book.name);
	printf("Введите год выпуска данной книги:");
	std::getline(std::cin, book.year);
	printf("Введите издание, издавшее даннее данную книги:");
	std::getline(std::cin, book.publisher);
	printf("Введите количество страниц в данной книге:");
	std::getline(std::cin, book.page);
}

// производит ввод данных на начальном этапе
void input_data_at_start(Book* book, int size, int& now_change_value) {
	for (int i = 0; i < size; i++) {
		printf("%s%d%s", "\n", now_change_value + 1, ".");
		input_data(book[i]);
		now_change_value++;
	}

}

// проверяет книгу на определенное условие
bool check_to_sign(Book book, int number_of_book_characteristic, std::string value_transmitted) {
	switch (number_of_book_characteristic) {
	case 1:
		if (book.registration_number == value_transmitted) return 0;
		break;
	case 2:
		if (book.writer == value_transmitted) return 0;
		break;
	case 3:
		if (book.name == value_transmitted) return 0;
		break;
	case 4:
		if (book.year == value_transmitted) return 0;
		break;
	case 5:
		if (book.publisher == value_transmitted) return 0;
		break;
	case 6:
		if (book.page == value_transmitted) return 0;
		break;
	};
	return 1;
}

// вводит значения до определенного условия
void input_to_sign(Book* book, int size, int& now_change_value, int number_of_book_characteristic, std::string value_transmitted) {
	for (int i = 0; i < size; i++) {
		printf("%s%d%s", "\n", now_change_value + 1, ".");
		input_data(book[i]);
		now_change_value++;
		if (check_to_sign(book[i], number_of_book_characteristic, value_transmitted) == 0) return;
	}
}

// выводит информацию об одной из книг
void output_data(Book book) {
	if (book.registration_number != "DELETE" && book.name != "DELETE") printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", book.registration_number.c_str(), book.writer.c_str(), book.name.c_str(), book.year.c_str(), book.publisher.c_str(), book.page.c_str());
}

// выводит информацию обо всех книгах из библиотеки
void output_all_data(Book* book, int now_change_value) {
	printf("\nНомер\t\tАвтор\t\tНазвание\tИздание\t\tИздательство\tСтраницы\n");
	for (int i = 0; i < now_change_value; i++) {
		output_data(book[i]);
	}
}

// расширение памяти
Book* my_realloc(Book*& book, int& size, int& new_memory) {
	Book* new_mass = new Book[size + new_memory];
	for (int i = 0; i < size; i++) {
		new_mass[i] = book[i];
	}
	delete[] book;
	book = nullptr;
	return new_mass;
}

// нахождения книги с определенными характеристиками и вывод их
void search_and_output(Book* book, int now_change_value) {
	printf("\nВыберите дальнейшее действие\n");
	printf("1.Ввести признак, основанный на регистрационном номере\n2.Ввести признак, основанный на имени писателя\n3.Ввести признак, основанный на названии книги\n4.Ввести признак, основанный на годе издания данной книги\n5.Ввести признак, основанный на издании, издавшее данную книги\n6.Ввести признак, основанный на количестве страниц в данной книге\nВведите продолжение:");
	std::string number_of_book_characteristic_string;
	int number_of_book_characteristic = check_input_up_to_six(number_of_book_characteristic_string);
	std::string book_characteristic;
	printf("\nВведите значение, основываясь на которое будет происходить нахождение определенной книги из библиотеки:");
	std::getline(std::cin, book_characteristic);
	printf("\nНомер\t\tАвтор\t\tНазвание\tИздание\t\tИздательство\tСтраницы\n");
	for (int i = 0; i < now_change_value; i++) {
		if (check_to_sign(book[i], number_of_book_characteristic, book_characteristic) == 0) output_data_one(book[i]);
	}
}

// добавление некоторого количества книг
void adding_book(Book*& book, int& size, int& now_change_value) { //добавляет значение
	std::cout << "Введите значение количества новых книг, необходимых к добавлению:";
	std::string input_data_string;
	int data = check_input_int(input_data_string);
	book = my_realloc(book, size, data);
	if (now_change_value == size) {
		for (int i = size; i < size + data; i++) {
			input_data(book[i]);
		}
	}
	else {
		for (int i = now_change_value; i < size + data; i++) {
			input_data(book[i]);
		}
	}
	size += data;
	now_change_value = size;
}

// удаление книги с определенным регистрационном номером
void delete_book(Book* book, int now_change_value) {
	printf("Введите идентификационный номер книги, необходимый к удалению:");
	std::string name;
	std::getline(std::cin, name);
	bool next = 0;
	int i = 0;
	for (; i < now_change_value; i++) {
		if (name == book[i].name) {
			next = 1;
			break;
		}
	}
	now_change_value--;
	for (int t = i; t < now_change_value; t++) {
		book[t] = book[t + 1];
	}
	book[now_change_value].name = "DELETE";
	Book* change_book = new Book[now_change_value];
	for (int i = 0; i < now_change_value; i++) {
		change_book[i] = book[i];
	}
	book = change_book;
}

// отсортировки массива вывод
void sort_library_Book_and_output(Book* book, int now_change_value) {
	int* mass_for_sort = new int[now_change_value];
	printf("Введите значение, относительно которого будет происходить сортировка\n1.Относительно года выпуска книги\n2.Относительно количества страниц книги\nВведите продолжение:");
	std::string next_string;
	int next = check_input_int_one_or_two(next_string);
	if (next == 1) {
		for (int i = 0; i < now_change_value; i++) {
			mass_for_sort[i] = std::stoi(book[i].year);
		}
		shell_sort(mass_for_sort, now_change_value);
		for (int i = 1; i < now_change_value; i++) {
			if (mass_for_sort[i] == mass_for_sort[i - 1]) mass_for_sort[i] = -1;
		}
		printf("\nНомер\t\tАвтор\t\tНазвание\tИздание\t\tИздательство\tСтраницы\n");
		for (int t = 0; t < now_change_value; t++) {
			for (int i = 0; i < now_change_value; i++) {
				if (std::stoi(book[i].year) == mass_for_sort[t] && mass_for_sort[i] != -1) output_data_one(book[i]);
			}
		}
	}
	else {
		for (int i = 0; i < now_change_value; i++) {
			mass_for_sort[i] = std::stoi(book[i].page);
		}
		shell_sort(mass_for_sort, now_change_value);
		for (int i = 1; i < now_change_value; i++) {
			if (mass_for_sort[i] == mass_for_sort[i - 1]) mass_for_sort[i] = -1;
		}
		for (int t = 0; t < now_change_value; t++) {
			for (int i = 0; i < now_change_value; i++) {
				if (std::stoi(book[i].page) == mass_for_sort[t] && mass_for_sort[i] != -1) output_data_one(book[i]);
			}
		}
	}
	delete[] mass_for_sort;
}
