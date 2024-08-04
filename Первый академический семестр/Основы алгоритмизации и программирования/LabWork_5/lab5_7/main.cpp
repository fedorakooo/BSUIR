#include <iostream>

long long pows(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    else if (b == 1) {
        return a;
    }
    else {
        return a * pows(a, b - 1);
    }
}
long long binpow(long long a, long long n, long  long t) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow(a, n - 1, t) % pows(10, t) * (a % pows(10, t))) % pows(10, t);
    else {
        long long b = binpow(a, n / 2, t) % pows(10, t);
        return ((b * b) % pows(10, t));
    }
}

int main() {
    for (long long i = 1;; i++) {
        long long k, n, t;
        std::cin >> k >> n >> t;
        if (k == 0 && n == 0 && t == 0) {
            std::cout << '\n';
            break;
        }
        else std::cout << "Case #" << i << ": " << binpow(k, n, t) << '\n';
    }
}