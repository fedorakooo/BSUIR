#include<iostream>

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "Задание выполнил Федорако Александр Анатольевич\nУчащийся группы 353502\n";
    std::cout << "Условие задания:Построить магический квадрат. Порядок квадрата задаётся пользователем.";
    while (true) {
        int n;
        std::cout << "Введите размер магического квадрата:";
        while (!(std::cin >> n) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Некорректный ввод" << "\n";
            std::cout << "Повторно введите размер магического квадрата:";
        }
        if (n == 1) {
            std::cout << "Error\n";
            continue;
        }
        int** mass = (int**)malloc(n * sizeof(int**));
        for (int i = 0; i < n; i++) {
            mass[i] = (int*)malloc(n * sizeof(int*));
        }

        for (int i = 0; i < n; i++) {
            for (int r = 0; r < n; r++) {
                mass[i][r] = 0;
            }
        }
        
        if (n % 2 == 1) {
            int chislo = 1;
            int r = 0, k = n / 2;
            mass[r][k] = chislo;
            chislo++, r--, k++;
            for (;chislo < n * n; r--, k++) {
                if (r < 0) {
                    if (mass[n - 1][k] != 0) {
                        mass[r + 1 + 1][k - 1] = chislo;
                        r += 2, k--;
                    }
                    else {
                        mass[n - 1][k] = chislo;
                        r = n - 1;
                    }
                }
                else if (k >= n) {
                    if (mass[r][0] != 0) {
                        mass[r + 1 + 1][k - 1] = chislo;
                        r += 2, k--;
                    }
                    else {
                        mass[r][0] = chislo;
                        k = 0;
                    }
                }
                else {
                    if (mass[r][k] != 0) {
                        mass[r + 1 + 1][k - 1] = chislo;
                        r += 2, k -= 1;
                    }
                    else {
                        mass[r][k] = chislo;
                    }
                }

                chislo++;


            }
            for (int k1 = 0; k1 < n;k1++) {
                for (int k2 = 0; k2 < n; k2++) {
                    if (mass[k1][k2] == 0) mass[k1][k2] = n * n;
                }
            }
        }

        else if ((n - 2) % 4 == 0) {
            int stor = n / 2, stor2 = n / 4;
            int chislo = 1;
            int r = 0, k = stor / 2;

            int** newmass = (int**)malloc(stor * sizeof(int**));
            for (int i = 0; i < stor; i++) {
                newmass[i] = (int*)malloc(stor * sizeof(int*));
            }
            for (int r = 0; r < stor; r++) {
                for (int k = 0; k < stor; k++) {
                    newmass[r][k] = 0;
                }
            }

            newmass[r][k] = chislo;
            chislo++, r--, k++;
            for (;chislo < stor * stor; r--, k++) {
                if (r < 0) {
                    if (newmass[stor - 1][k] != 0) {
                        newmass[r + 1 + 1][k - 1] = chislo;
                        r += 2, k--;
                    }
                    else {
                        newmass[stor - 1][k] = chislo;
                        r = stor - 1;
                    }
                }
                else if (k >= stor) {
                    if (newmass[r][0] != 0) {
                        newmass[r + 1 + 1][k - 1] = chislo;
                        r += 2, k--;
                    }
                    else {
                        newmass[r][0] = chislo;
                        k = 0;
                    }
                }
                else {
                    if (newmass[r][k] != 0) {
                        newmass[r + 1 + 1][k - 1] = chislo;
                        r += 2, k -= 1;
                    }
                    else {
                        newmass[r][k] = chislo;
                    }
                }

                chislo++;
            }

            for (int k1 = 0; k1 < stor;k1++) {
                for (int k2 = 0; k2 < stor; k2++) {
                    if (newmass[k1][k2] == 0) newmass[k1][k2] = stor * stor;
                }
            }
            for (int r = 0; r < stor; r++) {
                for (int k = 0; k < stor; k++) {
                    mass[r][k] = newmass[r][k];
                }
            }
            int razn = stor * stor;
            for (int r = stor, r1 = 0; r < n; r++, r1++) {
                for (int k = 0; k < stor; k++) {
                    mass[r][k] = newmass[r1][k] + razn * 3;
                }
            }
            for (int r = 0; r < stor; r++) {
                for (int k = stor, k1 = 0; k < n; k++, k1++) {
                    mass[r][k] = newmass[r][k1] + razn * 2;
                }
            }
            for (int r = stor, r1 = 0; r < n; r++, r1++) {
                for (int k = stor, k1 = 0; k < n; k++, k1++) {
                    mass[r][k] = newmass[r1][k1] + razn;
                }
            }

            int promesh1 = mass[0][0];
            mass[0][0] = mass[stor][0];
            mass[stor][0] = promesh1;

            int promesh2 = mass[stor - 1][0];
            mass[stor - 1][0] = mass[n - 1][0];
            mass[n - 1][0] = promesh2;

            int* stolb = (int*)malloc(stor * sizeof(int*));
          
            for (int r1 = 1; r1 < stor - 1; r1++) {
                stolb[r1] = mass[r1][1];
            }
            for (int r1 = 1, r2 = stor + 1; r1 < stor - 1; r1++, r2++) {
                mass[r1][1] = mass[r2][1];
            }
            for (int r1 = stor + 1, r2 = 1; r1 < 2 * stor - 1; r1++, r2++) {
                mass[r1][1] = stolb[r2];
            }

            int q = (n - 6) / 4;
            if (q > 0) {
                q = stor - q;
                for (; q < stor; q++) {
                    for (int r = 0; r < stor; r++) {
                        stolb[r] = mass[r][q];
                    }
                    for (int r = 0; r < stor; r++) {
                        mass[r][q] = mass[r + stor][q];
                    }
                    for (int r = 0; r < stor; r++) {
                        mass[r + stor][q] = stolb[r];
                    }
                }

                q = (n - 6) / 4;
                q = stor + q;
                for (; q > stor; q--) {
                    for (int r = 0; r < stor; r++) {
                        stolb[r] = mass[r][q];
                    }
                    for (int r = 0; r < stor; r++) {
                        mass[r][q] = mass[r + stor][q];
                    }
                    for (int r = 0; r < stor; r++) {
                        mass[r + stor][q] = stolb[r];
                    }
                }

            }

            for (int i = 0; i < stor; i++) {
                free(newmass[i]);
            }
            free(newmass);
            free(stolb); 
        }

        else if (n % 2 == 0) {
            int res = 1;
            for (int k = 0; k < n;k++) {
                for (int t = 0; t < n; t++, res++) {
                    mass[k][t] = res;
                }
            }
            res--;
            int stor = n / 2, stor2 = n / 4;

            for (int k = 0; k < stor2; k++) {
                for (int t = 0; t < stor2; t++) {
                    mass[k][t] = res - (k * n + t);
                }
            }

            for (int k = n - 1, k1 = 0; k >= n - stor2; k--, k1++) {
                for (int t = n - 1, t1 = 0; t >= n - stor2; t--, t1++) {
                    mass[k][t] = (k1 * n + t1) + 1;
                }
            }

            for (int k = 0; k < stor2; k++) {
                for (int t = n - stor2; t < n; t++) {
                    mass[k][t] = res - (k * n + t);
                }
            }

            for (int k = n - 1, k1 = 0; k > n - stor2 - 1; k--, k1++) {
                for (int t = stor2 - 1, t1 = n - stor2; t >= 0; t--, t1++) {
                    mass[k][t] = (k1 * n + t1) + 1;
                }
            }

            for (int k = n - stor2 - 1, k1 = stor2; k1 < n - stor2; k1++, k--) {
                for (int t = n - stor2 - 1, t1 = stor2; t1 < n - stor2; t1++, t--) {
                    mass[k][t] = k1 * n + t + 1;
                }
            }

        }

        for (int f = 0; f < n; f++) {
            for (int m = 0; m < n; m++) {
                std::cout << mass[f][m] << '\t';
            }
            std::cout << '\n';
        }

        for (int i = 0; i < n; i++) {
            free (mass[i]);
        }
        free(mass);
    }
}