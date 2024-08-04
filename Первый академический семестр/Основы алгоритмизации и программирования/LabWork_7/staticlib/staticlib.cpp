#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <string.h>

bool check_input_char(char* mass) {
	for (int i = 0; mass[i] != '\0'; i++) {
    	if (mass[i] != '0' && mass[i] != '1') return 0;
	}
	return 1;
}

bool check_input_string(std::string mass) {
	for (int i = 0; i < mass.size(); i++) {
		if (mass[i] != '0' && mass[i] != '1') return 0;
	}
	return 1;
}

void input_int(char* mass) {
	for (int i = 0; ;i++) {
		char a = getchar();
		if (a == '\n' && i == 0) i--;
		else if (a == '\n' && i > 0) {
			mass[i] = '\0';
			break;
		}
		else mass[i] = a;
	}
}
bool check_input_int(char* mass) {
	for (int i = 0; mass[i] != '\0'; i++) {
		if (!(isdigit(mass[i]))) return 0;
	}
	return 1;
}

