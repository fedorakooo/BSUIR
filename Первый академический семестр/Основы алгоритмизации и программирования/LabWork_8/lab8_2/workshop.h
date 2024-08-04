#pragma once
#include <string>
#include <iostream>


struct Workshop {
	std::string number;
	std::string* name = new std::string[1000];
	long long* quantity = new long long[1000];
	long long size = 0;
};

void input_data(Workshop* workshop, long long n);
void output_all_data(Workshop* workshop, long long n);
void output_data(Workshop* workshop, long long n);
Workshop* my_realloc(Workshop*& workshop, long long size, long new_memory);
void adding_workshop(Workshop*& workshop, long long& n);
void delete_workshop(Workshop* workshop, long long& n);
void change_workshop(Workshop* workshop, long long n);
