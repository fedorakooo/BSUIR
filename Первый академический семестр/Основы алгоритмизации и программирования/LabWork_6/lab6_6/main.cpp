#include <iostream>
#include <string>

long long factorial(long long a) {
    long long k = 1;
    for (long long i = 1; i <= a; i++) {
        k *= i;
    }
    return k;
}

int main() {
    std::string n;
    std::cin >> n;
    bool check = true;
    long long k = n.length();
    long long first_result = 1;
    first_result = factorial(k);
    long long second_result = 1;
    for (long long i = 0; i < k + 1; i++) {
        check = true;
        for (long long r = 0; r < i; r++) {
            if (n[r] == n[i]) {
                check = false;
                break;
            }
        }
        long long t = 1;
        if (check != false) {
            for (long long r = i + 1; r < k + 1; r++) {
                if (n[r] == n[i]) t++;
            }
        }
        second_result *= factorial(t);
    }
    std::cout << first_result / second_result;
}