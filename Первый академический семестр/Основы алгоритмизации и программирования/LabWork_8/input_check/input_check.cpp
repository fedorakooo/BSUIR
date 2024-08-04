#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

int check_input_int_one_or_two(std::string input_data) {
	std::getline(std::cin, input_data);
	if (input_data == "") return check_input_int_one_or_two(input_data);
	for (int i = 0; i < input_data.length(); i++) {
		if ((input_data[0] != '1' && input_data[0] != '2') || input_data.length() > 1) {
			std::cout << "Некорректный ввод!\n";
			return check_input_int_one_or_two(input_data);
		}
	}
	return (input_data[0] - '0');

}

int check_input_int(std::string input_data) {
	std::getline(std::cin, input_data);
	if (input_data == "") return check_input_int(input_data);
	for (int i = 0; i < input_data.length(); i++) {
		if (!(input_data[i] >= '0' && input_data[i] <= '9')) {
			std::cout << "Некорректный ввод!\n";
			return check_input_int(input_data);
		}
	}
	long result = std::stoi(input_data);
	return result;
}

int check_input_up_to_six(std::string input_data) {
	std::getline(std::cin, input_data);
	if (input_data == "") return check_input_up_to_six(input_data);
	for (int i = 0; i < input_data.length(); i++) {
		if (input_data[0] < '1' || input_data[0] > '7' || input_data.length() > 1) {
			std::cout << "Некорректный ввод!\n";
			return check_input_up_to_six(input_data);
		}
	}
	return (input_data[0] - '0');
}