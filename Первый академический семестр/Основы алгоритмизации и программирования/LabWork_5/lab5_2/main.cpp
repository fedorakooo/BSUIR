#include <iostream>
#include <cmath>
#include <windows.h>

int main()
{
	HINSTANCE load;
	load = LoadLibrary(L"dynamiclib.dll");

	typedef bool (*Is_cos_plus) (int*, int, int);
	typedef bool (*Is_mass_cos_plus)(int*, int, int);

	Is_cos_plus is_cos_plus;
	Is_mass_cos_plus is_mass_cos_plus;
		
	is_cos_plus = (Is_cos_plus)GetProcAddress(load, "Is_cos_plus");
	is_mass_cos_plus = (Is_mass_cos_plus)GetProcAddress(load, "Is_mass_cos_plus");

	setlocale(LC_ALL, "ru");
	std::cout << "������� �������� �������� ��������� �����������\n�������� ������ 353502\n";
	int start = 1;
	while (start != 2) {
	int n;
	std::cout << "\n������� ���������� �������� �������� X:";
	std::cin >> n;
	int* mass = new int[n];
	std::cout << "������� �������� X\n";
	for (int i = 0; i < n; i++) {
		std::cin >> mass[i];
	}
	if (is_mass_cos_plus(mass, 0, n - 1)) std::cout << "\n��� �������� cos(X) ������ ����";
	else std::cout << "\n�� ��� �������� cos(X) ������ ����";

	std::cout << "\n\n1.���������� ���������� ��������� ������\n2.��������� ���������� ���������\n������� ������� �����������:";
	std::cin >> start;
	}
	FreeLibrary(load);
}
