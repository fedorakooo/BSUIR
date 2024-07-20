#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "������� �������� �������� ��������� �����������\n�������� ������ 353502\n";
    std::cout << "������� ������:��� ��������� ������������ ������ �������� n^3 ����� ��������������� �����.���������� ���������� ��������� � ���������� ������ �����.";
    
    while (true) {
        std::cout << "������� ����������� ������� ����:";
        int n = 0;
        while (!(std::cin >> n) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "������������ ����" << "\n";
            std::cout << "�������� ������� ����������� ������� ����:";
        }

        int*** mass = (int***)malloc(n * sizeof(int***));
        for (int i = 0; i < n; i++) {
            mass[i] = (int**)malloc(n * sizeof(int**));
        }
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n; j++) {
                mass[i][j] = (int*)malloc(n * sizeof(int*));
            }
        }
        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                for (int z = 0;z < n; z++) {
                    mass[x][y][z] = 0;
                }
            }
        }
        
        int value = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                for (int z = 0;z < n; z++) {
                    std::cout << "������� �������� �������� ���� � ������������: x = " << x << " y = " << y << " z = " << z << ":";
                    while (!(std::cin >> value) || (std::cin.peek() != '\n')) {
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        std::cout << "������������ ����" << "\n";
                        std::cout << "�������� ������� �������� �������� ���� � ������������: x = " << x << " y = " << y << " z = " << z << ":";
                    }
                    mass[x][y][z] = value;
                }
            }
        }

        int result1 = 0, result2 = 0, result3 = 0, result4 = 0;
        for (int xyz = 0; xyz < n; xyz++) {
            result1 += mass[xyz][xyz][xyz];
        }
        for (int x = n - 1, yz = 0; yz < n; x--, yz++) {
            result2 += mass[x][yz][yz];
        }
        for (int z = n - 1, xy = 0; xy < n; xy++, z--) {
            result3 += mass[xy][xy][z];
        }
        for (int xz = n - 1, y = 0; y < n; xz--, y++) {
            result4 += mass[xz][y][xz];
        }

        for (int i = 0; i < n; i++) {
            for (int r = 0; r < n; r++) {
                free( mass[i][r]);
            }
        }
        for (int i = 0; i < n; i++) {
            free(mass[i]);
        }
        free(mass);

        std::cout << "\n�������� ����� ��������� ��������� ����� 1:" << result1; 
        std::cout << "\n�������� ����� ��������� ��������� ����� 2:" << result2;
        std::cout << "\n�������� ����� ��������� ��������� ����� 3:" << result3;
        std::cout << "\n�������� ����� ��������� ��������� ����� 4:" << result4 << '\n';
        int maxim = std::max(result1, std::max(result2, std::max(result3, result4)));
        int kolvo = 0;
        int valueen[4] = { result1, result2, result3, result4 };
        std::cout << "\n������������ �������� ����� ��������� ��������� ����������� ��������� ����� ";
        for (int i = 0; i < 4; i++) {
            if (valueen[i] == maxim) std::cout << i + 1 << ' ';
        }
        std::cout << "\n������������ �������� ����� ��������� ��������� �����:" << maxim << "\n\n";
    }
}