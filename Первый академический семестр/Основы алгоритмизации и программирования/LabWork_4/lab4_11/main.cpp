#include <iostream>

int main() {
    while (true) {
        int str, row;
        setlocale(LC_ALL, "ru");
        std::cout << "������� �������� �������� ��������� �����������\n�������� ������ 353502\n";
        std::cout << "������� ������:";
        std::cout << "�� ���� ������� ���� ��� ���� � ���� �������� n*m ��������,��� ������ '.' �������� ������ �����, � ������ '*' - �����.��������� ��������� ��� ���� �������, ��� � ������������ ����.";
        while (true) {
            std::cout << "\n������� ������ ���� ��� ���� � ������\n";
            std::cout << "\n������� ���������� �����:";
            std::cin >> str;
            std::cout << "������� ���������� ��������:";
            std::cin >> row;
            str += 2, row += 2;
            char** mass = new char* [str];
            for (int i = 0; i < row; i++) {
                mass[i] = new char[row];
            }
            for (int k = 0; k < str; k++) {
                for (int n = 0; n < row; n++) {
                    mass[k][n] = '.';
                }
            }
            int result;
            do {
                std::cout << "������� 1, ���� ������ ������ ��������\n������� 2, ���� ������ ������� ���� ����\n������� ������� �����������:";
                std::cin >> result;
                if (result == 2) {
                    for (int k = 1; k < str; k++) {
                        for (int n = 1; n < row; n++) {
                            if (mass[k][n] == '*') {
                                if (mass[k - 1][n - 1] != '*') {
                                    if (mass[k - 1][n - 1] == '.') mass[k - 1][n - 1] = '1';
                                    else if (mass[k - 1][n - 1] >= '1' && mass[k - 1][n - 1] <= '7') mass[k - 1][n - 1] += 1;
                                }
                                if (mass[k - 1][n] != '*') {
                                    if (mass[k - 1][n] == '.') mass[k - 1][n] = '1';
                                    else if (mass[k - 1][n] >= '1' && mass[k - 1][n] <= '7') mass[k - 1][n] += 1;
                                }
                                if (mass[k - 1][n + 1] != '*') {
                                    if (mass[k - 1][n + 1] == '.') mass[k - 1][n + 1] = '1';
                                    else if (mass[k - 1][n + 1] >= '1' && mass[k - 1][n + 1] <= '7') mass[k - 1][n + 1] += 1;
                                }
                                if (mass[k][n - 1] != '*') {
                                    if (mass[k][n - 1] == '.') mass[k][n - 1] = '1';
                                    else if (mass[k][n - 1] >= '1' && mass[k][n - 1] <= '7') mass[k][n - 1] += 1;
                                }
                                if (mass[k][n + 1] != '*') {
                                    if (mass[k][n + 1] == '.') mass[k][n + 1] = '1';
                                    else if (mass[k][n + 1] >= '1' && mass[k][n + 1] <= '7') mass[k][n + 1] += 1;

                                }
                                if (mass[k + 1][n + 1] != '*') {
                                    if (mass[k + 1][n + 1] == '.') mass[k + 1][n + 1] = '1';
                                    else if (mass[k + 1][n + 1] >= '1' && mass[k + 1][n + 1] <= '7') mass[k + 1][n + 1] += 1;
                                }
                                if (mass[k + 1][n] != '*') {
                                    if (mass[k + 1][n] == '.') mass[k + 1][n] = '1';
                                    else if (mass[k + 1][n] >= '1' && mass[k + 1][n] <= '7') mass[k + 1][n] += 1;

                                }
                                if (mass[k + 1][n - 1] != '*') {
                                    if (mass[k + 1][n - 1] == '.') mass[k + 1][n - 1] = '1';
                                    else if (mass[k + 1][n - 1] >= '1' && mass[k + 1][n - 1] <= '7') mass[k + 1][n - 1] += 1;

                                }
                            }
                        }
                    }
                }
                if (result == 1) {
                    int x, y;
                    std::cout << "������� ���������� ��������(������, �������):";
                    std::cin >> x >> y;
                    x++, y++;
                    mass[x][y] = '*';
                }
                for (int k = 1; k < str - 1; k++) {
                    for (int n = 1; n < row- 1; n++) {
                        std::cout << mass[k][n] << '\t';
                    }
                    std::cout << '\n';
                }
            } while (result == 1);
            for (int i = 0; i < row; i++) {
                delete mass[i];
            }
            delete[] mass;

            std::cout << "\n\n";
        }
    }
}
