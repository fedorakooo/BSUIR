#include <iostream> 
#include <fstream>
#include <string>		
#include "../input_check/input_check.h"
#include "../sortlibrary/sort_library.h"
#include "workshop.h"

int main() {
	setlocale(LC_ALL, "ru");

	//создаем объект класса ofstream
	std::ofstream input;
	std::ofstream output;

	//вызываем метод open для работы с объектом класса
	input.open("InputData.txt");
	output.open("OutputData.txt");

	//проверяем открытие файла на ошибку
	if (!input.is_open() || !output.is_open()) {
		std::cout << "Ошибка открытия файла!\n";
	}
	else {
		std::cout << "Задание выполнил студент группы 353502, Федорако Александр.\n";
		std::cout << "Вариант выполнения задания:8.\n";
		std::cout << "Условие задания: Для заданного цеха необходимо вывести количество выпущенных изделий по каждому наименованию в порядке убывания количества.\n\n\n";

		std::cout << "Введите изначальное количество различных цехов:";
		std::string n_string;
		long long n;
		n = check_input_int(n_string);

		Workshop* workshop = new Workshop[n];

		std::cout << "\nВведите номера всех первоначальных цехов\n";
		for (int i = 0; i < n; i++) {
			std::cout << i + 1 << ':';
			std::getline(std::cin, workshop[i].number);
		}

		std::string action_string;
		long long action;
		do {
			std::cout << "\n\nВведите 1, если хотите совершить операции над цехами, 2 в ином случаи:";
			action = check_input_int_one_or_two(action_string);
			if (action == 1) {
				std::cout << "\nВыберите дальнейшее действие.\n1.Заполнить определенный цех вводимыми значениями\n2.Вывести значения определенного цеха в порядке возрастания его количественного значения\n";
				std::cout << "3.Добавить определенный цех\n4.Удалить определенный цех\n5.Изменить значения определенного цеха\n6.Вывести полное содержимое всех цехов в отсортированном порядке\n\nВведите продолжение:";
				std::string next_action_string;
				long next_action = check_input_up_to_six(next_action_string);
				switch (next_action) {
				case 1:
					input_data(workshop, n);
					break;
				case 2:
					output_data(workshop, n);
					break;
				case 3:
					adding_workshop(workshop, n);
					break;
				case 4:
					delete_workshop(workshop, n);
					break;
				case 5:
					change_workshop(workshop, n);
					break;
				case 6:
					output_all_data(workshop, n);
					break;
				}
			}
		} while (action == 1);
		output_all_data(workshop, n);

		input << "Информация обо всех цехах.\n";
		for (int i = 0; i < n; i++) {
			input << "\nНаименование цеха номер " << i + 1 << ':' << workshop[i].number << '\n';
			input << "Наименование продукции\t\tКоличество продукции\n";
			for (int t = 0; t < workshop[i].size; t++) input << workshop[i].name[t] << "\t\t\t" << workshop[i].quantity[t] << "\n";
			input << "Количество различной продукции:" << workshop[i].size << "\n\n";
		}

		output << "Выводимые значения.";
		output << "\n";
		for (int i = 0; i < n; i++) {
			long long* intermediate_value = new long long[workshop[i].size];
			for (int k = 0; k < workshop[i].size; k++) {
				intermediate_value[k] = workshop[i].quantity[k];
			}
			for (int k = 0; k < workshop[i].size; k++) {
				selection_sort(intermediate_value, workshop[i].size);
			}
			if (workshop[i].number != "DELETE") {
				output << "Полная отсортированная информация об цехе под номером:" << workshop[i].number;
				output << "\nНаименование продукции\tКоличество продукции\n";
				for (int k = 0; k < workshop[i].size; k++) {
					for (int t = 0; t < workshop[i].size; t++) {
						if (intermediate_value[k] == workshop[i].quantity[t] && workshop[i].name[t] != "") {
							if (!(k > 0 && intermediate_value[k - 1] == intermediate_value[k])) output << workshop[i].name[t] << "\t\t\t" << workshop[i].quantity[t] << '\n';
						}
					}
				}
			}
			output << '\n';
			delete[] intermediate_value;
		}
		printf("\n\nСпасибо за внимание!");
		input.close();
		output.close();
		delete[] workshop;
	}
}


		