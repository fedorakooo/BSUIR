#include <iostream>
#include <string>
#include <fstream>
#include "../input_check/input_check.h"
#include "../sortlibrary/sort_library.h"

union WeightPerson {
	int weight;
	double weight_double;
};

class Player {
public:
	std::string name;
	std::string team;
	std::string country;
	std::string number;
	WeightPerson weight_player;
	int age;
	int height;
};


void only_input_data(Player& player) {
	std::cout << "������� �������� ������� ����������:";
	std::getline(std::cin, player.team);
	std::cout << "������� ������ ����������:";
	std::getline(std::cin, player.country);
	std::cout << "������� ����� ����������:";
	std::getline(std::cin, player.number);
	std::string weight_string;
	std::string age_string;
	std::string height_string;
	std::cout << "������� ������� ����������:";
	player.age = check_input_int(age_string);
	std::cout << "������� ��� ����������:";
	player.weight_player.weight = check_input_int(weight_string);
	std::cout << "������� ���� ����������:";
	player.height = check_input_int(height_string);
}

void input_data(Player* player, int size, std::ofstream& input) { //��������� ����������
	std::cout << "\n������� ��� ������, ��� ���������� ���������� �� ��� � ���� ������:";
	std::string some_number;

	std::getline(std::cin, some_number);
	bool next = 0;
	int i = 0;
	for (; i < size; i++) {
		if (some_number == player[i].name) {
			next = 1;
			break;
		}
	}
	if (next) {
		only_input_data(player[i]);
		input << "\n��� ������:" << player[i].name << '\n';
		input << "������� ������:" << player[i].team << '\n';
		input << "������ ������:" << player[i].country << '\n';
		input << "����� ������:" << player[i].number << '\n';
		input << "��� ������" << player[i].weight_player.weight << '\n';
		input << "���� ������" << player[i].height << '\n';
		input << "������� ������" << player[i].age << '\n';
	}

	else {
		std::cout << "������!\n";
	}
}

Player* my_realloc(Player*& player, int size, int new_memory) {
	Player* new_mass = new Player[size + new_memory];
	for (int i = 0; i < size; i++) {
		new_mass[i] = player[i];
	}
	delete[] player;
	player = nullptr;
	return new_mass;
}

void adding_Player(Player*& player, int& n, std::ofstream& input) { //��������� ��������
	std::cout << "������� �������� ���������� ����� �����������, ����������� � ����������:";
	std::string input_data_string;
	long input_data = check_input_int(input_data_string);
	player = my_realloc(player, n, input_data);
	for (long long i = n; i < n + input_data; i++) {
		std::cout << "������� ��� ���������� ��� ������� " << i + 1 << ':';
		std::getline(std::cin, player[i].name);
	}

	input << "������ �� ����� ����������\n";
	for (int i = n; i < n + input_data; i++) {
		only_input_data(player[i]);
		input << "\n��� ������:" << player[i].name << '\n';
		input << "������� ������:" << player[i].team << '\n';
		input << "������ ������:" << player[i].country << '\n';
		input << "����� ������:" << player[i].number << '\n';
		input << "��� ������" << player[i].weight_player.weight << '\n';
		input << "���� ������" << player[i].height << '\n';
		input << "������� ������" << player[i].age << '\n';
	}
	n += input_data;
}

void delete_player(Player* player, int n, std::ofstream& input) {
	std::cout << "������� ��� ����������, ������������ � ���������� �� �������:";
	std::string name;
	std::getline(std::cin, name);
	bool next = 0;
	int i = 0;
	for (; i < n; i++) {
		if (name == player[i].number) {
			next = 1;
			break;
		}
	}
	for (int t = i; t < n - 1; t++) {
		player[t] = player[t + 1];
	}
	input << "����������� �������� ���������� � ������:" << name;
	player[n - 1].number = "DELETE";
}

void change_player(Player* player, int n, std::ofstream& input) {
	std::cout << "������� ��� ����������, ������ �������� ���������� ���������������:";
	std::string name;
	std::getline(std::cin, name);
	bool next = 0;
	int i = 0;
	for (; i < n; i++) {
		if (name == player[i].number) {
			next = 1;
			break;
		}
	}
	if (next) {
		only_input_data(player[i]);
		input << "��������� ��������� ������ � ����������, ��� ������ " << name;
		input << "����� ������\n";
		input << "\n��� ������:" << player[i].name << '\n';
		input << "������� ������:" << player[i].team << '\n';
		input << "������ ������:" << player[i].country << '\n';
		input << "����� ������:" << player[i].number << '\n';
		input << "��� ������" << player[i].weight_player.weight << '\n';
		input << "���� ������" << player[i].height << '\n';
		input << "������� ������" << player[i].age << '\n';
	}
	else std::cout << "������";
}

bool check_for_condition(Player player) {
	if (player.name != "DELETE" && player.number != "DELETE") return 1;
	else return 0;
}
void output_one_data(Player player) {
	std::cout << "\n\n��� ����������:" << player.name;
	std::cout << "\n������� ����������:" << player.team;
	std::cout << "\n������ ����������:" << player.country;
	std::cout << "\n������� ����������:" << player.age;
	std::cout << "\n��� ����������:" << player.weight_player.weight;
	std::cout << "\n���� ����������:" << player.height;
}

void output_all_data(Player* player, int size) {
	for (int i = 0; i < size; i++) {
		if (check_for_condition(player[i])) {
			output_one_data(player[i]);
		}
	}
}

bool check_to_repetition(std::string* teams, int point, std::string team) {
	for (int i = 0; i < point; i++) if (teams[i] == team) return 1;
	return 0;
}

void output_some_data(Player* player, int size) {
	std::cout << "\n\n����� ������� �������:";
	std::string* teams = new std::string[size];
	int point = 1;
	teams[0] = player[0].team;
	for (int i = 0; i < size; i++) {
		if (check_to_repetition(teams, point, player[0].team) == 0) {
			teams[point] = player[i].team;
			point++;
		}
	}
	int* mass_all_age = new int[point];
	for (int i = 0; i < point; i++) mass_all_age[i] = 0;
	int* mass_quantity = new int[point];
	for (int i = 0; i < point; i++) mass_quantity[i] = 0;
	for (int i = 0; i < point; i++) {
		for (int t = 0; t < size; t++) {
			if (teams[i] == player[t].team) {
				mass_all_age[i] += player[t].age;
				mass_quantity[i]++;
			}
		}
	}
	double* mass_average_age = new double[point];
	for (int i = 0; i < point; i++) mass_average_age[i] = (double)mass_all_age[i] / mass_quantity[i]++;
	int min_year = mass_average_age[0];
	int point_min_year = 0;
	for (int i = 1; i < point; i++) {
		if (mass_average_age[i] < min_year) {
			min_year = mass_average_age[i];
			point_min_year = i;
		}
	}
	std::cout << teams[point_min_year] << '\n';
	std::cout << "\n\n������ �������";
	for (int i = 0; i < size; i++) {
		if (teams[point_min_year] == player[i].team) output_one_data(player[i]);
	}
}

void output_some_data_end(Player* player, int size, std::ofstream& output) {
	std::cout << "\n\n����� ������� �������:";
	std::string* teams = new std::string[size];
	int point = 1;
	teams[0] = player[0].team;
	for (int i = 0; i < size; i++) {
		if (check_to_repetition(teams, point, player[0].team) == 0) {
			teams[point] = player[i].team;
			point++;
		}
	}
	int* mass_all_age = new int[point];
	for (int i = 0; i < point; i++) mass_all_age[i] = 0;
	int* mass_quantity = new int[point];
	for (int i = 0; i < point; i++) mass_quantity[i] = 0;
	for (int i = 0; i < point; i++) {
		for (int t = 0; t < size; t++) {
			if (teams[i] == player[t].team) {
				mass_all_age[i] += player[t].age;
				mass_quantity[i]++;
			}
		}
	}
	double* mass_average_age = new double[point];
	for (int i = 0; i < point; i++) mass_average_age[i] = (double)mass_all_age[i] / mass_quantity[i]++;
	int min_year = mass_average_age[0];
	int point_min_year = 0;
	for (int i = 1; i < point; i++) {
		if (mass_average_age[i] < min_year) {
			min_year = mass_average_age[i];
			point_min_year = i;
		}
	}
	std::cout << teams[point_min_year] << '\n';
	std::cout << "\n\n������ �������";
	for (int i = 0; i < size; i++) {
		if (teams[point_min_year] == player[i].team) output_one_data(player[i]);
	}

	std::cout << "����� ������� �������:";
	std::cout << teams[point_min_year];
	output << "\n\n������ �������";
	for (int i = 0; i < size; i++) {
		if (teams[point_min_year] == player[i].team && check_for_condition(player[i])) {
			output << "\n��� ������:" << player[i].name << '\n';
			output << "������� ������:" << player[i].team << '\n';
			output << "������ ������:" << player[i].country << '\n';
			output << "����� ������:" << player[i].number << '\n';
			output << "��� ������" << player[i].weight_player.weight << '\n';
			output << "���� ������" << player[i].height << '\n';
			output << "������� ������" << player[i].age << '\n';
		}
	}
}