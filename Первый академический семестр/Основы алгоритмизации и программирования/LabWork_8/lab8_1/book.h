#pragma once

#include <string>

struct Book {
	std::string registration_number;
	std::string writer;
	std::string name;
	std::string year;
	std::string publisher;
	std::string page;
};

void input_data(Book& book);
void input_data_at_start(Book* book, int size, int& now_znac_change);
bool check_to_sign(Book book, int number_of_book_characteristic, std::string value_transmitted);
void input_to_sign(Book* book, int size, int& now_znac_change, int number_of_book_characteristic, std::string value_transmitted);
void output_data(Book book);
void output_all_data(Book* book, int now_znac_change);
Book* my_realloc(Book*& book, int& size, int& new_memory);
void search_and_output(Book* book, int now_znac_change);
void adding_book(Book*& book, int& size, int& now_znac_change);
void delete_book(Book* book, int now_znac_change);
void sort_library_Book_and_output(Book* book, int now_znac_change);