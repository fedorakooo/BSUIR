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
	std::cout << "Введите название команды спортсмена:";
	std::getline(std::cin, player.team);
	std::cout << "Введите страну спортсмена:";
	std::getline(std::cin, player.country);
	std::cout << "Введите номер спортсмена:";
	std::getline(std::cin, player.number);
	std::string weight_string;
	std::string age_string;
	std::string height_string;
	std::cout << "Введите возраст спортсмена:";
	player.age = check_input_int(age_string);
	std::cout << "Введите вес спортсмена:";
	player.weight_player.weight = check_input_int(weight_string);
	std::cout << "Введите рост спортсмена:";
	player.height = check_input_int(height_string);
}

void input_data(Player* player, int size, std::ofstream& input) { //заполняет значениями
	std::cout << "\nВведите имя игрока, для добавления информации об нем в базу данных:";
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
		input << "\nИмя игрока:" << player[i].name << '\n';
		input << "Команда игрока:" << player[i].team << '\n';
		input << "Страна игрока:" << player[i].country << '\n';
		input << "Номер игрока:" << player[i].number << '\n';
		input << "Вес игрока" << player[i].weight_player.weight << '\n';
		input << "Рост игрока" << player[i].height << '\n';
		input << "Возраст игрока" << player[i].age << '\n';
	}

	else {
		std::cout << "Ошибка!\n";
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

void adding_Player(Player*& player, int& n, std::ofstream& input) { //добавляет значение
	std::cout << "Введите значение количества новых спортсменов, необходимых к добавлению:";
	std::string input_data_string;
	long input_data = check_input_int(input_data_string);
	player = my_realloc(player, n, input_data);
	for (long long i = n; i < n + input_data; i++) {
		std::cout << "Введите имя спортсмена под номером " << i + 1 << ':';
		std::getline(std::cin, player[i].name);
	}

	input << "Данные об новых спортменах\n";
	for (int i = n; i < n + input_data; i++) {
		only_input_data(player[i]);
		input << "\nИмя игрока:" << player[i].name << '\n';
		input << "Команда игрока:" << player[i].team << '\n';
		input << "Страна игрока:" << player[i].country << '\n';
		input << "Номер игрока:" << player[i].number << '\n';
		input << "Вес игрока" << player[i].weight_player.weight << '\n';
		input << "Рост игрока" << player[i].height << '\n';
		input << "Возраст игрока" << player[i].age << '\n';
	}
	n += input_data;
}

void delete_player(Player* player, int n, std::ofstream& input) {
	std::cout << "Введите имя спортсмена, необходимого к исключению из турнира:";
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
	input << "Произведено удаление спортсмена с именем:" << name;
	player[n - 1].number = "DELETE";
}

void change_player(Player* player, int n, std::ofstream& input) {
	std::cout << "Введите имя спортсмена, данные которого необходимо отредактировать:";
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
		input << "Произошло изменение данных о спортсмене, под именем " << name;
		input << "Новые данные\n";
		input << "\nИмя игрока:" << player[i].name << '\n';
		input << "Команда игрока:" << player[i].team << '\n';
		input << "Страна игрока:" << player[i].country << '\n';
		input << "Номер игрока:" << player[i].number << '\n';
		input << "Вес игрока" << player[i].weight_player.weight << '\n';
		input << "Рост игрока" << player[i].height << '\n';
		input << "Возраст игрока" << player[i].age << '\n';
	}
	else std::cout << "Ошибка";
}

bool check_for_condition(Player player) {
	if (player.name != "DELETE" && player.number != "DELETE") return 1;
	else return 0;
}
void output_one_data(Player player) {
	std::cout << "\n\nИмя спортсмена:" << player.name;
	std::cout << "\nКоманда спортсмена:" << player.team;
	std::cout << "\nСтрана спортсмена:" << player.country;
	std::cout << "\nВозраст спортсмена:" << player.age;
	std::cout << "\nВес спортсмена:" << player.weight_player.weight;
	std::cout << "\nРост спортсмена:" << player.height;
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
	std::cout << "\n\nСамая молодая команда:";
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
	std::cout << "\n\nИгроки команды";
	for (int i = 0; i < size; i++) {
		if (teams[point_min_year] == player[i].team) output_one_data(player[i]);
	}
}

void output_some_data_end(Player* player, int size, std::ofstream& output) {
	std::cout << "\n\nСамая молодая команда:";
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
	std::cout << "\n\nИгроки команды";
	for (int i = 0; i < size; i++) {
		if (teams[point_min_year] == player[i].team) output_one_data(player[i]);
	}

	std::cout << "Самая молодая команда:";
	std::cout << teams[point_min_year];
	output << "\n\nИгроки команды";
	for (int i = 0; i < size; i++) {
		if (teams[point_min_year] == player[i].team && check_for_condition(player[i])) {
			output << "\nИмя игрока:" << player[i].name << '\n';
			output << "Команда игрока:" << player[i].team << '\n';
			output << "Страна игрока:" << player[i].country << '\n';
			output << "Номер игрока:" << player[i].number << '\n';
			output << "Вес игрока" << player[i].weight_player.weight << '\n';
			output << "Рост игрока" << player[i].height << '\n';
			output << "Возраст игрока" << player[i].age << '\n';
		}
	}
}