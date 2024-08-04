#include <iostream>
#include <string>
#include "../input_check/input_check.h"
#include "../sortlibrary/sort_library.h"

struct Workshop {
	std::string number;
	std::string* name = new std::string[1000];
	long long* quantity = new long long[1000];
	long long size = 0;
};

// ������ ������ �� ����� �� �����
void input_data(Workshop* workshop, long long n) {
	std::cout << "\n������� ����� ����, ��� ���������� � ���� ������������ ���������:";
	std::string some_number;
	std::getline(std::cin, some_number);
	bool next = 0;
	int i = 0;
	for (; i < n; i++) {
		if (some_number == workshop[i].number) {
			next = 1;
			break;
		}
	}
	if (next) {
		std::cout << "������� ���������� ��������������� ����� ���������:";
		std::string input_quantity_string;
		long input_quantity = check_input_int(input_quantity_string);
		for (int k = 0; k < input_quantity; k++) {
			std::cout << "\n\n������� �������� � ������������ ��������� ���� ����� " << workshop[i].number << ':';
			std::getline(std::cin, workshop[i].name[workshop[i].size]);
			std::cout << "������� �������� � ���������� ��������� ���� ����� " << workshop[i].number << ':';
			std::string n_string;
			long n;
			n = check_input_int(n_string);
			workshop[i].quantity[workshop[i].size] = n;
			workshop[i].size++;
		}
	}
	else {
		std::cout << "������!\n";
	}
}

// ������� �������� ���� �������� � ��������������� �������
void output_all_data(Workshop* workshop, long long n) {
	std::cout << "\n\n";
	for (int i = 0; i < n; i++) {
		long long* intermediate_value = new long long[workshop[i].size];
		for (int k = 0; k < workshop[i].size; k++) {
			intermediate_value[k] = workshop[i].quantity[k];
		}
		for (int k = 0; k < workshop[i].size; k++) {
			selection_sort(intermediate_value, workshop[i].size);
		}
		if (workshop[i].number != "DELETE") {
			std::cout << "������ ��������������� ���������� �� ���� ��� �������:" << workshop[i].number;
			std::cout << "\n������������ ���������\t���������� ���������\n";
			for (int k = 0; k < workshop[i].size; k++) {
				for (int t = 0; t < workshop[i].size; t++) {
					if (intermediate_value[k] == workshop[i].quantity[t] && workshop[i].name[t] != "") {
						if (!(k > 0 && intermediate_value[k - 1] == intermediate_value[k])) std::cout << workshop[i].name[t] << "\t\t\t" << workshop[i].quantity[t] << '\n';
					}
				}
			}
		}
		std::cout << '\n';
		delete[] intermediate_value;
	}
}

// ������� �������� ������ ������� � ��������������� �������
void output_data(Workshop* workshop, long long n) {
	std::cout << "\n������� ����� ����, ��� ������ �������� � ���������� ���������:";
	std::string some_number;
	std::getline(std::cin, some_number);
	bool next = 0;
	int i = 0;
	for (; i < n; i++) {
		if (some_number == workshop[i].number) {
			next = 1;
			break;
		}
	}
	if (next) {
		long long* intermediate_value = new long long[workshop[i].size];
		for (int k = 0; k < workshop[i].size; k++) {
			intermediate_value[k] = workshop[i].quantity[k];
		}
		for (int k = 0; k < workshop[i].size; k++) {
			selection_sort(intermediate_value, workshop[i].size);
		}
		for (int k = 0; k < workshop[i].size; k++) {
			for (int t = 0; t < workshop[i].size; t++) {
				if (intermediate_value[k] == workshop[i].quantity[t] && workshop[i].number != "DELETE") {
					if (!(k > 0 && intermediate_value[k - 1] == intermediate_value[k]) && workshop[i].name[t] != "") std::cout << workshop[i].name[t] << "\t\t\t" << workshop[i].quantity[t] << '\n';
				}
			}
		}
		delete[] intermediate_value;
	}
	else {
		std::cout << "������!\n";
	}
}

//��������� ������������ ������
Workshop* my_realloc(Workshop*& workshop, long long size, long new_memory) {
	Workshop* new_mass = new Workshop[size + new_memory];
	for (int i = 0; i < size; i++) {
		new_mass[i] = workshop[i];
	}
	delete[] workshop;
	workshop = nullptr;
	return new_mass;
}

// ��������� ������������ ��������
void adding_workshop(Workshop*& workshop, long long& n) {
	std::cout << "������� �������� ���������� ����� �����, ����������� � ����������:";
	std::string line;
	long input_data = check_input_int(line);
	workshop = my_realloc(workshop, n, input_data);
	for (long long i = n; i < n + input_data; i++) {
		std::cout << "������� ������������ ���� ��� ������� " << i + 1 << ':';
		std::string value;
		std::getline(std::cin, value);
		workshop[i].number = value;
	}
	n += input_data;
}

// ������� �������� ������ �� �����
void delete_workshop(Workshop* workshop, long long& n) {
	std::cout << "������� ������������ ����, ������������ � ��������:";
	std::string name;
	std::getline(std::cin, name);
	bool next = 0;
	int i = 0;
	for (; i < n; i++) {
		if (name == workshop[i].number) {
			next = 1;
			break;
		}
	}
	n--;
	for (int t = i; t < n; t++) {
		workshop[t] = workshop[t + 1];
	}
	workshop[n].number = "DELETE";
	Workshop* change_workshop = new Workshop[n];
	for (int i = 0; i < n; i++) {
		change_workshop[i] = workshop[i];
	}
	workshop = change_workshop;
}

// �������� �������� ������ �� �����
void change_workshop(Workshop* workshop, long long n) {
	std::cout << "������� �������� ����, ������ �������� ���������� ���������������:";
	std::string name;
	std::getline(std::cin, name);
	bool next = 0;
	int i = 0;
	for (; i < n; i++) {
		if (name == workshop[i].number) {
			next = 1;
			break;
		}
	}
	for (int t = 0; t < workshop[i].size; t++) {
		workshop[i].name[t] = "";
	}
	if (next) {
		std::cout << "������� ���������� ��������������� ����� ���������:";
		std::string input_quantity_string;
		long input_quantity = check_input_int(input_quantity_string);
		for (int k = 0; k < input_quantity; k++) {
			std::cout << "\n\n������� �������� � ������������ ��������� ���� ����� " << workshop[i].number << ':';
			std::getline(std::cin, workshop[i].name[workshop[i].size]);
			std::cout << "������� �������� � ���������� ��������� ���� ����� " << workshop[i].number << ':';
			std::string n_string;
			long n = check_input_int(n_string);
			workshop[i].quantity[workshop[i].size] = n;
			workshop[i].size++;
		}
	}
	else std::cout << "������";
}
