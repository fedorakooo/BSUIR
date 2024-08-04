#include <iostream>
#include <clocale>
#include <string>

using namespace std;

void input_check() {
    bool a = 1;
    do {
        a = 1;
        char* str = new char[100];
        cin.getline(str, sizeof(str));
        int n = strlen(str);
        for (int i = 0; i < n; i++) {
            if (!isdigit(str[i])) {
                std::cout << "Некоректный ввод в символе номер " << i + 1 << '\n';
                a = 0;
            }
        }
        if (a == 1) {
            for (int i = 0; i < n;i++) {
                std::cout << str[i];
            }
            delete[] str;
        }
        else if (a == 0) {
            std::cout << "Пожалуйста повторите попытку\n";
            delete[] str;
        }

    } while (a == 0);
}