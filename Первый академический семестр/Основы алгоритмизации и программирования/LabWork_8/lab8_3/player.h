#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../input_check/input_check.h"
#include "../sortlibrary/sort_library.h"

union Weight_person {
	int weight;
	double weight_double;
};

class Player {
public:
	std::string name;
	std::string team;
	std::string country;
	std::string number;
	Weight_person weight_player;
	int age;
	int height;
};

void only_input_data(Player& player);
void input_data(Player* player, int size, std::ofstream& input);
Player* my_realloc(Player*& player, int size, int new_memory);
Player* my_realloc(Player*& player, int size, int new_memory);
void adding_Player(Player*& player, int& n, std::ofstream& input);
void delete_player(Player* player, int n, std::ofstream& input);
void change_player(Player* player, int n, std::ofstream& input);
void output_one_data(Player player);
void output_all_data(Player* player, int size);
bool check_to_repetition(std::string* teams, int point, std::string team);
void output_some_data(Player* player, int size);
void output_some_data_end(Player* player, int size, std::ofstream& output);