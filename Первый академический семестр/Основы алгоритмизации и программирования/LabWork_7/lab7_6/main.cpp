#include <iostream>
#include <string>
#include "../staticlib/staticlib.h"

int const SIZE = 243;

long long powl(int n, int k) {
	if (k == 0) return 1;
	else return powl(n, k - 1) * n;
}
void cout_conversion(std::string str) {
	for (int i = 0; i < 5; i++) {
		std::cout << str[i];
	}
}
bool drink_barrel(int drink, int toxin) {
	return (toxin == drink) ? 0 : 1;
}

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "������� �������� �������� ���������\n������ 353502\n";
	std::cout << "\n\n" << "��������� ��� �������� ��� �����, �� ��� �������.\n";
	std::cout << "�������� ����� �������� �������� � ��� ����� ���������� 240 ����� ����.\n";
	std::cout << "������ � ���� ��������� ��������������� �� ����� ������������,������� �������� �� � ���� �� �����.\n";
	std::cout << "��� �� ��������, ��� �������, ������� ��� �����, ������� � ������� 24 �����.\n";
	std::cout << "�� ��������� �������� ��� ���, �� ���� 48 �����.\n� �������� ���� ���� �����, �������� �� ����� ������������, ����� ������, � ����� ������ ����� ��.\n";
	std::cout << "�� ������� ���� �������� � ���������� �� ������ ����� ����� �� ��� �����, ��� ����� ��������� ���� �� ������� ���.\n";
	int continuation = 1;
	while (continuation == 1) {
	int toxin = 0;
		std::cout << "������� ���� ���� �������, ������� �� ������...\n";
		std::cout << "�� ��� ������������, ��� �������� �����, �� ������ ���������� ��������, ������� ����������� �����:";
		bool pop = 0;
		std::cin >> toxin;
		while(toxin > 240 || toxin < 0) {
			if (pop = 1) std::cout << "������������, �� ��������� �������� �����, � ������� ������ ���?\n������� � ���� � �������� �������, ���� ��� �� �������!!!\n������ ��� �� ����� ������, ������� ����������� �����!:";
			std::cin >> toxin;
			pop = 1;
		}
		bool life_slaves[5]{ 1,1,1,1,1 };
		char str_result[6] = "00000";
		std::cout << "\n��� � ������� ������ ����, �� ��������� 2 ���, ���� �����������!\n";
		int life_rabs = 0;
		for (int i = 0; i < 5; i++) {
			if (life_slaves[i] == 1) life_rabs++;
		}
		std::cout << "�� ������ ������ ����� " << life_rabs << " �������� �����\n";
		std::cout << "��, ��, ��, ��� ������� �� ������� ���������, ��� �� ����� ������, ���� �������� ��� �����.\n";
		std::cout << "������� �� ������ ����� �����, ������ ������, ��� ������, ���� ������ ������������ �� ������ ������������,��� ��� ���� �������\n";
		std::cout << "��� ������� ���� ����������� ��� ������� ��������� � ���������, ��� �� � ���������\n";
		for (int i = 1; i <= SIZE; i += 3) {
			life_slaves[4] = drink_barrel(i, toxin);
			if (life_slaves[4] == 0) break;
		}
		for (int i = 3; i < SIZE; i += 9) {
			for (int r = i; r < i + 3; r++) {
				if (life_slaves[3] == 0) break;
				life_slaves[3] = drink_barrel(r, toxin);
			}
		}
		for (int i = 9; i < SIZE; i += 27) {
			for (int r = i; r < i + 9; r++) {
				life_slaves[2] = drink_barrel(r, toxin);
				if (life_slaves[2] == 0) break;
			}
			if (life_slaves[2] == 0) break;
		}
		for (int i = 27; i < SIZE; i += 81) {
			for (int r = i; r < i + 27; r++) {
				if (life_slaves[1] == 0) break;
				life_slaves[1] = drink_barrel(r, toxin);
			}
			if (life_slaves[1] == 0) break;
		}
		for (int i = 81; i < 81 + 81; i++) {
			life_slaves[0] = drink_barrel(i, toxin);
			if (life_slaves[0] == 0) break;
		}
		for (int i = 0; i < 5; i++) {
			if (life_slaves[i] == 0) {
				str_result[4 - i] = '1';
			}
		}
		std::cout << "��� � ������ �����,�� �������� � ����� ���, ������� �������� ������� �� ��� �������� �����\n";
		life_rabs = 0;
		for (int i = 0; i < 5; i++) {
			if (life_slaves[i] == 1) life_rabs++;
		}
		std::cout << "�� ������ ������ ����� " << life_rabs << " �������� �����\n";
		std::cout << "���� ������� ��� �������� ������� �� ������, ��� �� �� ���!\n";
		std::cout << "������� ������� ���, ������� ������ ����� ���������� �����!\n";
		std::cout << "��� ����� ����������, � ������� ������� ���� �������� �����?) ������� ���, ��� ���������� ���� ������ ��������";
		for (int i = 2; i < SIZE && life_slaves[4] == 1; i += 3) {
			life_slaves[4] = drink_barrel(i, toxin);
		}
		for (int i = 6; i < SIZE && life_slaves[3] == 1; i += 9) {
			for (int r = i; r < i + 3 && life_slaves[3] == 1; r++) {
				life_slaves[3] = drink_barrel(r, toxin);
			}
		}
		for (int i = 18; i < SIZE && life_slaves[2] == 1; i += 27) {
			for (int r = i; r < i + 9 && life_slaves[2] == 1; r++) {
				life_slaves[2] = drink_barrel(r, toxin);
			}
		}
		for (int i = 54; i < SIZE && life_slaves[1] == 1; i += 81) {
			for (int r = i; r < i + 27 && life_slaves[1] == 1; r++) {
				life_slaves[1] = drink_barrel(r, toxin);
			}
		}
		for (int i = 162; i < SIZE && life_slaves[0] == 1; i++) {
			life_slaves[0] = drink_barrel(i, toxin);
		}

		for (int i = 0; i < 5; i++) {
			if (life_slaves[i] == 0 && str_result[4 - i] == '0') {
				str_result[4 - i] = '2';
			}
		}
		long long result = 0;
		for (int i = 4; i >= 0; i--) {
			result += powl(3, 4 - i) * ((int)(str_result[4 - i]) - '0');
		}
		life_rabs = 0;
		for (int i = 0; i < 5; i++) {
			if (life_slaves[i] == 1) life_rabs++;
		}
		std::cout << "\n��� � ������ ���� ���������, �� ��� ��� � ��� � ������?\n";
		std::cout << "�� ������ ������ ����� " << life_rabs << " �������� �����\n";
		std::cout << "�� ��� �� ����� �����, ��� �� � ��� ��� � �������, � � ���� ��� ������ �������!\n";
		std::cout << "��, ��� ��� ����� ��� ������� " << result << " ������ ����� ������ ��, ���� �������� � ����� �������� - ���� ������\n";
		std::cout << "����� �� ��������� ������ ���������������, ������� ��� ������ ��� �����, � ����������� ������� ��� ��������������.\n";
		std::cout << "\n\n" << "����� �� ����������, ��� � ������ ������������ ��������, ������� ������ �������, ������ ��������� ���!!!\n";
		std::cout << '\n' << "�� ������ ������������ ��� ���������������� ��� ���?(1 - ��, 2 - ���)\n";
		std::cout << "������� �����������:";
		std::cin >> continuation;
		std::cout << "\n\n";
	}
	std::cout << "������� �� ��������!!!";
}
