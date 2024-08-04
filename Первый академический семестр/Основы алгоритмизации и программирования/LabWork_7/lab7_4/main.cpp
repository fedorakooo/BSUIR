#include <iostream>
#include "../staticlib/staticlib.h"

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "������� �������� �������� ���������\n������ 353502\n������� �������:��������� ����� �� ��������� ���� � ������������ �����\n";
    int continuation = 1;
    while (continuation == 1) {
        long long a;
        long long n;
        char first[100], second[100];
        do {
            std::cout << "������� ������ �����, ����������� ��� �������� �� ���������:";
            input_int(first);
        } while (check_input_int(first) == 0);
        a = atoi(first);

        do{
            std::cout << "������� ������ �����, �� ������� ������ ����������� ���������:";
            input_int(second);
        } while (check_input_int(second) == 0);
        n = atoi(second);

        bool condition = true;

        while (n <= a && !condition) {
            bool k = n ^ a;
            if (k || n == a) { 
                std::cout << "������ ����� ������� ��� ������� �� ������.\n";
                break;
                condition = false;
            }
            n *= 2;
        }
        if (condition) {
            std::cout << "������ ����� �� ������� ��� ������� �� ������.\n";
        }
        std::cout << '\n' << "������ ��������� �������� ��� ���?(1 - ��, 2 - ���)\n";
        std::cout << "������� �����������:";
        std::cin >> continuation;
        std::cout << "\n\n";
    }
    std::cout << "������� �� ��������!!!";
}
