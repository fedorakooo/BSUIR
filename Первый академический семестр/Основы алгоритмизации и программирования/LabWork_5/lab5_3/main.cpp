#include <iostream>

void first_conclusion(long long* mass, long long n) {
    for (long long i = 0; i < n; i++) {
        std::cout << mass[i] << '\t';
    }
    std::cout << '\n';
}
void second_conclusion(long long** mass, long long n) {
    std::cout << '\n';
    for (long long k = 0; k < n; k++) {
        for (long long i = 0; i < n; i++) {
            std::cout << mass[k][i] << '\t';
        }
        std::cout << '\n';
    }
}
int input_check() {
    bool is_correct = 1;
    do {
        is_correct = 1;
        char* str = new char[100];
        std::cin.getline(str, sizeof(str));
        int n = strlen(str);
        for (int i = 0; i < n; i++) {
            if (!isdigit(str[i])) {
                std::cout << "����������� ���� � ������� ����� " << i + 1 << '\n';
                is_correct = 0;
            }
        }
        if (is_correct) {
            for (int i = 0; i < n;i++) {
                return std::atoi(str);
            }
            delete[] str;
        }
        else {
            std::cout << "���������� ��������� �������\n";
            delete[] str;
        }

    } while (not is_correct);
}


int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "������� �������� �������� ��������� �����������\n�������� ������ 353502\n";
    std::cout << "������� �������:��� ��������� ������������ ������ ����� ����� � ������������ n. ������� ������������ ������ �� ���������, ������������� �� ������� ��������� ������� � ������� ������ ��������.��������� ������������ ��������� ������������� �������.��������� ������ � ��������� ������������ ������� �� �����.";
    long long start = 1;
    while (start == 1) {
        std::cout << "\n\n������� ����������� �������:";
        long long n;
        n = input_check();

        long long** matr = new long long* [n];
        for (long long i = 0; i < n; i++) {
            matr[i] = new long long[n];
        }

        long long* mass = new long long[n];

        long long number;
        std::cout << "\n1.��������� ������ ���������� �������.\n2.��������� ������ �������, ��������� � ������.\n������� ������� �����������:";
        do {
            number = input_check();
        } while (number != 1 && number != 2);


        if (number == 1) {
            for (long long k = 0; k < n; k++) {
                for (long long i = 0; i < n; i++) {
                    matr[k][i] = (rand() % 100) + 1;
                }
            }

            second_conclusion(matr, n);

            long long k = 0;
            for (long long i = 0; i < n; i++) {
                if (matr[i][i] % 2 == 0) {
                    mass[k] = matr[i][i];
                    k++;
                }
            }
            if (k == 0) {
                std::cout << "\n\n��������� � ������ ��������� �� ������� ��������� �� �������.\n";
            }
            else {
                std::cout << "\n\n�������� � ������ ��������� �� ������� ���������:";
                first_conclusion(mass, k);
            }
            if (k != 0) {
                std::cout << "\n\n������������ ������ ���������, ������� �� ������� ��������� �����:";
                long long result = 1;
                for (long long i = 0; i < k; i++) {
                    result *= mass[i];
                }
                std::cout << result << '\n';
            }
        }
        else {
            std::cout << "\n";
            for (long long k = 0; k < n; k++) {
                for (long long i = 0; i < n; i++) {
                    std::cout << "������� �������� �������� � ������������ " << k << ' ' << i << " :";
                    matr[k][i] = input_check();
                }
            }

            second_conclusion(matr, n);

            long long k = 0;
            for (long long i = 0; i < n; i++) {
                if (matr[i][i] % 2 == 0) {
                    mass[k] = matr[i][i];
                    k++;
                }
            }
            if (k == 0) {
                std::cout << "\n\n��������� � ������ ��������� �� ������� ��������� �� �������.\n";
            }
            else {
                std::cout << "\n�������� � ������ ��������� �� ������� ���������:";
                first_conclusion(mass, k);
            }
            if (k != 0) {
                std::cout << '\n' << "\n������������ ������ ���������, ������� �� ������� ��������� �����:";
                long long result = 1;
                for (long long i = 0; i < k; i++) {
                    result *= mass[i];
                }
                std::cout << result << '\n';
            }
        }


        for (long long i = 0; i < n; i++) {
            delete[] matr[i];
        }
        delete [] matr;

        delete [] mass;
        std::cout << "\n\n1.���������� ���������� ��������� ������\n2.��������� ���������� ���������\n������� ������� �����������:";
        std::cin >> start;

    }
}